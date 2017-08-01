#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
ll twoends(int a[],int n);
int main()
{

    int n;
    cin>>n;int j=0;
    while(n)
    {   ll s=0;j++;
        int a[n];
        for(int i=0;i<n;i++)
         {

            scanf("%d",&a[i]);s=s+a[i];
        }
       ll d= twoends(a,n);

      printf("In game %d, the greedy strategy might lose by as many as %lld points.",j,(2*d-s));
      cin>>n;
    }
    return 0;
}
ll twoends(int a[],int n)
{
 int i,j,gap;int w,x,y,z;
 ll dp[1001][1001];
 for(i=0;i<n;i++)
    memset(dp[i],0,sizeof(dp[i]));
 for(gap=0;gap<n;gap++)
 {
     for(i=0,j=gap;j<n;j++,i++)
     {

             w=(i+1<=j-1 && a[j]>a[i+1])?dp[i+1][j-1]:0;
             x=(i+2<=j  &&  a[i+1]>=a[j])?dp[i+2][j]:0;
             y=(i<=j-2 && a[j-1]>a[i])?dp[i][j-2]:0;
             z=(i+1<=j-1 && a[i]>=a[j-1])?dp[i+1][j-1]:0;
         dp[i][j]=max(a[i]+max(w,x),a[j]+max(y,z));

     }

 }

 return dp[0][n-1];
}

