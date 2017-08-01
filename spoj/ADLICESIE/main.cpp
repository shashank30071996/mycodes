#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{

    ll t;
    cin>>t;
    while(t--)
    { ll n;
        cin>>n;
        ll a=(n*(n+1)*(2*n+1))/12;
        ll b=(n*(n+1))/4;
        ll c=(n*(n+1)*(n+2))/6;
        cout<<a+b+1<<"    "<<c<<endl;
    }
    return 0;
}
