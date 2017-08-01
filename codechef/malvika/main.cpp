#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
     char c[100];
     scanf("%s",c);
     puts(c);
     int na,nb=0;int n=0;
     for(int i=0;i<100;i++)
     {
         if(c[i]=='a')
            na++;
          else
            nb++;
     }
     printf("%d\n",na);
     printf("%d\n",nb);
     if(na==nb)
        n=na;
     else if(na==0 || nb==0)
     {
         int n=0;
     }
     else
     {
         int n=min(na,nb);

     }
    printf("%d\n",n);
 }
}

 for( i=1;i<n+1;i++)
     b[a[i]]++;
   for(int i=2;i<n+1;i++)
   {
       if(b[i]==0)
        printf("%d ",i);
   }
