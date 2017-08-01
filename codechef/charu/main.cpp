#include <iostream>

using namespace std;
typedef long long int ll;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       ll pais=(ll)(n/0.25);ll c=1;ll five,one=0;
       for(ll i=2;i<=pais;i=i+2)
       {
           five=i/2;c++;
           if(five>=2)
           {
              c=c+five/2;
              c=c+five/4;
              c=c+five/3;
           }

       }
       cout<<(c%1000000007)<<endl;
   }
}
