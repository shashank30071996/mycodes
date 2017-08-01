#include <bits/stdc++.h>

using namespace std;
void print(int dp[]);
int main()
{
    cout << "Hello world!" << endl;
    int n;cin>>n;cout<<n<<endl; int p[n];
    for(int i=0;i<n;i++)
     {

        cin>>p[i];}
        print(p);
    int i,j;int dp[n+1];memset(dp,0,sizeof(dp));
     print(dp);
    for(i=1;i<=n;i++)
    {
       int mx=INT_MIN;
        for(j=0;j<n;j++)
        {
            mx=max(mx,p[j]+dp[i-j-1]);
        }
        dp[i]=mx;
        print(dp);
    }
    cout<<dp[n]<<endl;

    return 0;
}
void print(int dp[])
{ cout<<"dp"<<endl;
    int n=sizeof(dp)/sizeof(*dp);
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<dp[i]<<endl;
}
