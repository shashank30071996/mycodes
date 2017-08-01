#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
typedef long long int ll;
#define mod 1000000009
int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
              int n;

              scanf("%d",&n);

              long long sum=0;
              bool flag=1;
              int min=0;
              int count=0;
              long long num=0;
              ll x;

              for(int i=0;i<n;i++)
              {
                      scanf("%lld",&x);

                      if(x>0)
                      {
                                sum=sum+x%mod;
                                flag=0;
                      }

                      if(x==0)
                      num++;

                      if(min>x)
                     {

                      min=x;count++;}

                      if(min==x)
                      count++;

              }

              if(flag)
              printf("%d %lld\n",min,(count+num)%mod);

              else
              printf("%lld %lld\n",sum,(int)(pow(2,num))%mod);

    }



    return 0;

}
