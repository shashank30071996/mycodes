#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,m;
        scanf("%lld",&n);
        scanf("%lld",&m);



       if((n*m)%2==0)
            printf("%s\n","Yes");
       else
            printf("%s\n","No");
    }
}
