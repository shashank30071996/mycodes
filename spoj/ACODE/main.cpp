#include <bits/stdc++.h>
#define MAX 26
using namespace std;
bool ok(char a, char b);
int main()
{   while(true)
   {
    string s;
    cin>>s;
    int l=s.length();
    int dp[l][2];
    if(s.compare("0")==0)break;
    dp[0][0]=0;dp[0][1]=1;
    for(int i=1;i<l;i++)
    {
        if(!ok(s[i-1],s[i]))
            dp[i][0]=0;
        else
            dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
        if(s[i]=='0')
            dp[i][1]=0;
    }
    cout<<dp[l-1][0]+dp[l-1][1]<<endl;
   }
}
bool ok(char a, char b) {
    return (a-'0')*10 + (b-'0') <= MAX;
}
