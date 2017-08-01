#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long int ll;
double kroot(ll x,ll k);
int main()
{
    unsigned long long int a,b,result;
    unsigned long long int power[65],temp;
    int i,j;

    while(1)
    {
        scanf("%lld",&a);
        scanf("%lld",&b);
        if(a==0)
            break;
        result=0;
        power[0]=0;
        power[1]=b-a+1;

        a--;
        for(i=2;i<64;i++)
        {
            power[i]=(int)kroot( b, i);
            while(pow((power[i]-1),(long double)i)>=b)
            {
                power[i]--;
            }
            while(pow((power[i]+1),(long double)i)<=b)
            {
                power[i]++;
            }

            temp=(int)floor(kroot( b, i));
            while(pow((temp-1),(long double)i)>=a)
            {
                temp--;
            }
            while(pow((temp+1),(long double)i)<=a)
            {
                temp++;
            }
            power[i]-=temp;
        }
        for(i=63;i>=1;i--)
        {
            for(j=i*2;j<64;j=j+i)
            {
                power[i]-=power[j];
            }
        }
        for(i=1;i<64;i++)
        {
            result+=i*power[i];
        }
        printf("%lld\n",result);
    }

    return 0;
}

double kroot(ll x,ll k)
{
     if (k == 1) {
         return x;
    }
    if (k == 2) {
         return sqrt(x);
    }
    return exp(log(x) / k);
}
