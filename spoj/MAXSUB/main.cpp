#include <bits/stdc++.h>

using namespace std;
#define mod 1000000009
typedef long long int ll;
ll maxsum=0;ll coun=0;
ll countsubset(ll set[],ll n,ll ite,ll sum);
int main()
{
    cout << "Hello world!" << endl;
    int t;cin>>t;ll mx=INT_MIN;
    while(t--)
    {
        ll n;
        cin>>n;
        ll set[n];bool check[n];int c=0;
        for(int i=0;i<n;i++)
        {
            cin>>set[i];
            if(set[i]<0)
            {
              check[i]=false;c++;
            }
            else
                check[i]=true;
            mx=max(mx,set[i]);

        }
        if(c==n)
            maxsum=mx;
        else
        {


        for(int i=0;i<n;i++)
        {
          if(check[i])
                maxsum=maxsum+set[i];
        }
        }
       ll k= countsubset(set,n,0,0);
        cout<<maxsum<<" "<<k<<endl;
    }
    return 0;
}

ll countsubset(ll set[],ll n,ll ite,ll sum)
{    cout<<ite<<"  "<< coun<<" "<<sum<<endl;coun=coun%10;
    if(sum==maxsum)
        {
             coun=coun+1;
             // constraint check
        if( ite + 1 < n && sum - set[ite] + set[ite+1] <= maxsum )
        {
            // Exclude previous added item and consider next candidate
           coun=coun+ countsubset(set,  n, ite+1,sum-set[ite]);
        }

        }
    else
    {
        for(ll i=ite;i<n;i++)
        {
             if( sum + set[i] <= maxsum )
                {
                    // consider next level node (along depth)
                   coun=coun+ countsubset(set,n,ite+1,sum+set[i]);
                }
        }
    }
    return coun;
}
