#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int func(int pos[],ll n,ll c,int mid);
void print(int a[],ll n);
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,c;
       cin>>n;
       cin>>c;
       int positions[n];
       for(int i=0;i<n;i++)
        cin>>positions[i];
        sort(positions,positions+n);
        print(positions,n);
       int start=0;
       int end=positions[n-1]-positions[0];
       while(start+1<end)
       {
           int mid=(start+end)/2;
           if(func(positions,n,c,mid)==1)
           {
               start=mid;
           }
           else
           {
               end=mid;
           }
       }
       cout<<start<<endl;

   }
}

int func(int pos[],ll n,ll c,int mid)
{
    int lastpos=pos[0];int i=1;int cows=1;
    while(i<n)
    {
        if(pos[i]-lastpos>=mid)
        {
            cows++;
            lastpos=pos[i];
            if(cows==c)
                return 1;
        }
        i++;
    }
    return 0;
}

void print(int a[],ll n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;

}
