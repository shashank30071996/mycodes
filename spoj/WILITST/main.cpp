#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{

    ll n;
    cin>>n;
    if((n&(n-1))==0)
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;
    return 0;
}
