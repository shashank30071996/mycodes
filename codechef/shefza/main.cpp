#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        if(m==0 || m==1)
           m=2;
        bool a[n-m+1],b[n-m+1];

       int flag=m;
       for(int i=0;i<(n-m+1);i++)
         {

          a[i]=true;b[i]=0;}
       for(int j=2;j<=sqrt(n);j++)
    {
        if(j>=m && j<=n && b[j-flag]==0)
        {
            a[j-flag]=true;b[j-flag]=1;
        }
       for(int k=m/j;k<=(n/j);k++)

          { if(b[j*k-flag]==0)
           {
               a[j*k-flag]=false;b[j*k-flag]=1;}
          }
    }
       for(int l=m;l<=n;l++)
    {
        if(a[l-flag]==true)
            cout<<l<<endl;
    }


    }

    return 0;
}
