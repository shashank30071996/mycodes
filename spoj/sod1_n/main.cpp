#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll sod(ll n);
int main()
{

    ll a,b;
    cin>>a;cin>>b;
    while(a!=-1 )
    {
        cout<<sod(b)-sod(a-1)<<endl;
        cin>>a;cin>>b;
    }
    return 0;
}

ll sod(ll n)
{
    if(n<10)
        return n*(n+1)/2;
    int d=(int)log10(n);
    int a[d+1];
     a[0]=0;a[1]=45;
     for(int i=2;i<=d;i++)
        a[i]=a[i-1]*10+45*ceil(pow(10,i-1));
     int p=ceil(pow(10,d));
     int msd=n/p;
     return msd*a[d] + (msd*(msd-1)/2)*p +
           msd*(1+n%p) + sod(n%p);
}
