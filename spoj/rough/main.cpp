#include<bits/stdc++.h>
using namespace std;
void activities(int n);
vector< pair<int,int> > arr(100000);vector<int>::iterator it;
#define mo 100000000
int main()
{
    int n;
    cin>>n;
    while(n!=-1)
    {
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].second;cin>>arr[i].first;
        }
        sort(arr.begin(),arr.begin()+n);

    activities( n);cin>>n;}
}
 void activities(int n)
 {
     vector<int> intsec;
     int dp[n][2];memset(dp,0,sizeof(dp[0][0])*n*2);
     dp[0][1]=1;
     intsec.push_back(arr[0].first);
     for(int i=1;i<n;i++)
     {
         dp[i][0]=dp[i-1][0]+dp[i-1][1];
             if(dp[i][0]>=mo)
            dp[i][0]=dp[i][0]-mo;
         if(arr[i].second<intsec[0])
         {
             dp[i][1]=1;
         }
         else
         {
              it= upper_bound(intsec.begin() , intsec.end() , arr[i].second );;int index=it-intsec.begin();index--;
             dp[i][1]=1+dp[index][0]+dp[index][1];
            if(dp[i][1]>=mo)
            dp[i][1]=dp[i][1]-mo;

         }
         intsec.push_back(arr[i].first);
     }
     printf("%0.8d\n",(dp[n-1][0]+dp[n-1][1])%mo);
 }
