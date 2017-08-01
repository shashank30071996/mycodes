#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int calcx(int i,int e);
int calcy(int i,int e,int n);
stack<int> x;
stack<int> y;
stack<int> p;
int calcx(int i,int e)
{
    int a=i-1;
    if(i==0)
        a=-2;
    else
    {
        while(!x.empty() && x.top()<=e )
        {
            x.pop();
            a--;
            cout<<"  "<<a<<endl;
        }
        a=(x.empty())?-2:a;
    }
    x.push(e);
    return a;
}
int calcy(int i,int e,int n)
{
    int a=i+1;
    if(i==n-1)
        a=-2;
    else
    {
        while(!y.empty() && y.top()<=e )
        {
            y.pop();
            a++;
            cout<<" ya : "<<a<<endl;
        }
        a=(y.empty())?-2:a;
    }
    y.push(e);
    return a;
}
int main()
{
    cout << "Hello world!" << endl;
   int n;cin>>n;int i=0;int x,y;int h[n];
   ll a[n];
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }
   for(i=0;i<n;i++)
   {
       h[i]=calcx(i,a[i])+1;
       y=calcy(n-1-i,a[n-1-i],n)+1;
       cout<<"x: "<<x<<" y: "<<y<<"  <"<<x+y<<endl;
   }
    return 0;
}
