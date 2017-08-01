#include <bits/stdc++.h>

using namespace std;
int editpath(string a,string b,int m,int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {


   string a,b;
   cin>>a;
   cin>>b;
   int m=a.length();
   int n=b.length();
   cout<<editpath(a,b,m,n)<<endl;
    }

}

int editpath(string a,string b,int m,int n)
{
    int dp[m+1][n+1];memset(dp,0,sizeof(int)*(m+1)*(n+1));
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=1+min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
