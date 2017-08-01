#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin>>n;int i;int t;
   int a[n+1];a[1]=0;
   for( i=1;i<n+1;i++)
      {
       cin>>t;
       if(t!=0)
        a[t]=1;
        else
          a[i]=0;
      }
    for(i=1;i<n+1;i++)
    {
        if(a[i]!=1)
            printf("%d ",i);
    }



}
