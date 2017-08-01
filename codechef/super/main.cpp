#include <iostream>

using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int n,k;
      cin>>n;cin>>k;int coin=0;
      for(int i=1;i<=k;i++)
      {
          if((n%i)>coin)
            coin=n%i;
      }
     cout<<coin<<endl;
   }
}
