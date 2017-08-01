#include <bits/stdc++.h>

using namespace std;
void minamount(int a[],int k,int n);
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;cin>>k;
        int a[k];
        for(int i=0;i<k;i++)
            cin>>a[i];
        minamount(a,k,n );
    }


    return 0;
}
void minamount(int a[],int k,int n)
{
    int dp[k+1];memset(dp,0,sizeof(dp));int b[k+1];memset(b,0,sizeof(b));
    int i,j,mn,temp;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j<=i && a[j-1]!=-1)
            {
                if(dp[i]==0)
                {
                    temp=a[j-1]+dp[i-j];
                    mn=temp;b[i]=j;
                }
                else
                {
                    temp=a[j-1]+dp[i-j];
                    mn=min(temp,dp[i]);b[i]=j;
                }

            }
            dp[i]=mn;
        }
        dp[i]=mn;
    }
    if(b[k]!=k)
        cout<<"-1"<<endl;
    else
        cout<<dp[k]<<endl;

}
