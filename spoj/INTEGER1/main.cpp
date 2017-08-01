#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll power[65];memset(power,0,sizeof(power));
    ll a;ll b;
    cin>>a;cin>>b;
    int i,j;power[1]=b-a+1;
    for(i=2;i<=64;i++)
    {
        power[i]=kroot(b,i);
        while(pow(power[i]-1,i)>=b)
            power[i]--;
        while(pow(power[i]+1,i)<=b)
            power[i]++;
        cout<<i<<":"<<power[i]<<endl;
        ll temp=kroot(a,i);
        while(pow(temp-1,i)>=a)
            temp--;
        while(pow(temp+1,i)<=)
    }

}
