#include <bits/stdc++.h>

using namespace std;typedef long long int ll;
int getsum(int bit[],int i);
void updatebit(int bit[],int val,int i);
int getnext(int i);
int getparent(int i);ll n;
int main()
{
    cout << "Hello world!" << endl;
    int t;cin>>t;
    while(t--)
    {
        cin>>n;int a[n];int i;int b[n];ll sum=0;
        for(i=0;i<n;i++)
           {
            cin>>a[i];b[i]=a[i];}

        int bit[n+1];
        memset(bit,0,sizeof(bit));
        sort(a,a+n);
        for(i=0;i<n;i++)
        {
            int p=lower_bound(a,a+n,b[i])-a;b[i]=p;cout<<p<<endl;
        }
        for(i=0;i<n;i++)
       {    cout<<b[i]<<endl;
           sum=sum+getsum(bit,b[i]);
           updatebit(bit,a[b[i]],b[i]+1);}

            cout<<sum<<endl;


    }
    return 0;
}


void updatebit(int bit[],int val,int i)
{
    while(i<n+1)
    {
        bit[i]=bit[i]+val;
        i=getnext(i);
    }
}

int getnext(int i)
{
    return(i+(i & -i));
}
int getparent(int i)
{
    return(i-(i & -i));
}

int getsum(int bit[],int i)
{
    i=i+1;int sum=0;
    while(i<n+1)
    {
        sum=sum+bit[i];
        i=getparent(i);
    }
    return sum;
}


