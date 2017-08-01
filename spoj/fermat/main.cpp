#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void print(vector<int> &a,ll k,int pos,ll ans);
ll binary(vector<int> &v,ll k);
ll check(vector<int> &a,ll k,ll mid);
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
    ll m,k;
    cin>>m;cin>>k;
    vector<int> a(m);int i;
    for(i=0;i<m;i++)
        cin>>a[i];
    a.push_back(0);
    ll ans=binary(a,k);
    print(a,k,a.size()-2,ans);
    }
    return 0;
}
ll binary(vector<int> &v,ll k)
{
    ll low=1;ll high=LLONG_MAX,
     ans=LLONG_MAX, mid;
    while(low<high)
    {
        mid=(low+high)>>1;
        if(check(v,k,mid))
        {
            ans=min(ans,mid);
            high=mid;
        }
        else low=mid+1;

    }
    return ans;
}

ll check(vector<int> &a,ll k,ll mid)
{
    int n=a.size();int i=0;ll count=0;int total=1;
    while(i<n)
    {
        if((long long)a[i]>mid)
            return false;
       else if(count+(long long)a[i]>mid)
        {
            total++;count=0;
        }

        else
        {
           count=count+a[i];i++;
        }
    }
    if(total<=k)
        return true;
    return false;
}
void print(vector<int> &a,ll k,int pos,ll ans)
{
    int postill=-1;ll count=0;int i=0;
    for(i=pos;i>=0;i--)
    {
        if(count+a[i]>ans || i==k-2){
            print(a,k-1,i,ans);
            postill=i;
            break;
        }
        else
            count+=a[i];
    }
     if(postill >= 0)
        printf("/ ");
    for( i = postill +1 ; i<= pos ; i++)
        printf("%d ", a[i]);

}
