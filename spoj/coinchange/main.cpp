#include <bits/stdc++.h>

using namespace std;
void coin(int p[],int n,int k);
int main()
{
    cout << "Hello world!" << endl;
     int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;cin>>k;
        int a[k];
        for(int i=0;i<k;i++)
            cin>>a[i];
            coin(a,n,k);
    }

    return 0;
}
void coin(int p[],int n,int k)
{
    int dp[n+1][k];memset(dp,0,sizeof(dp));
    int i,j,x=0,y=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<k;j++)
        {
            if(i==0)
            {
                dp[i][j]=1;
            }
            else
            {
                 x=(p[j]<=i)?dp[i-p[j]][j]:0;
                 y=(j>=1)?dp[i][j-1]:0;
                 dp[i][j]=x+y;
            }


        }
    }
    cout<<dp[n][k-1]<<endl;
}
