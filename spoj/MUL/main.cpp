#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int check(int val[],int wt[],int e,int f,int n);
int main()
{

    int t;cin>>t;while(t--){
    ll a;ll b;cin>>a;cin>>b;ll n;cin>>n;
    int wt[n];int val[n];
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
        cin>>wt[i];
    }
    check(val,wt,a,b,n);
   } return 0;
}
int check(int val[],int wt[],int e,int f,int n)
{  f=f-e;
    int ans[f+1];memset(ans,0,sizeof(ans));
    int i=0,j=0;
    for(i=1;i<=f;i++)
    {
        ans[i]=-1;

        for(j=0;j<n;j++)
        {
            if(wt[j]<=i && ans[i-wt[j]]!=-1 && (ans[i]==-1 ||( val[j]+ans[i-wt[j]]<=ans[i])))
            {
                ans[i]=val[j]+ans[i-wt[j]];
            }
        }

    }
    if( ans[f]==-1)
        cout<<"This is impossible."<<endl;
    else
        printf("The minimum amount of money in the piggy-bank is %d.\n",ans[f]);
        return 0;
}
