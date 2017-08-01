#include <bits/stdc++.h>

using namespace std;
void seventy(int a[],int n,int sum);
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int sum=0;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];sum=sum+a[i];
        }
        seventy(a,n,sum);
    }

    return 0;
}
void seventy(int a[],int n,int sum)
{
    int dp[n+1][sum+1];

    int i,j,maxsum=0;int ans=0;
    for(i=0;i<=n;i++)
      memset(dp[i],0,sizeof(dp[i]));



    for(i=0;i<=n;i++)
        dp[i][0]=1;
    for(i=1;i<=sum;i++)
        dp[0][i]=0;
    for(i=1;i<=n;i++)
    {
        maxsum=maxsum+a[i-1];
        dp[i][a[i-1]]=1;
        for(j=1;j<=maxsum;j++)
        {
            if(dp[i-1][j]==1)dp[i][j]=1;
            if(j>=a[i-1] && dp[i-1][j-a[i-1]]) dp[i][j]=1;
        }
    }
    for(i=1;i<=sum;i++)
    {    if(dp[n][i])
        ans=i+ans;
    }
    cout<<ans<<endl;

}
