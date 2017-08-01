#include <bits/stdc++.h>

using namespace std;
int lcs(string s);
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int lc=s.length()-lcs(s);
        cout<<lc<<endl;
    }
    return 0;
}

int lcs(string s)
{
    int n=s.length();
    int dp[n+1][n+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s[i-1]==s[n-j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[n][n];
}
