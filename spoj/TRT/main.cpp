#include <bits/stdc++.h>

using namespace std;
int a[2000];
int cache[2000][2000];int n;
int profit(int be,int en ,int year);
int main()
{


    cin>>n;
    int i;

    for( i=0;i<n;i++)
        cin>>a[i];



    memset(cache,-1,sizeof(cache));
    int ans=profit(0,n-1,1);
    cout<<ans<<endl;
    return 0;
}
int profit(int be,int en,int year )
{
    if(be>en)
        return 0;

    if(cache[be][en]!=-1)
        return cache[be][en];

    return (cache[be][en]= max(profit(be+1,en,year+1)+year*a[be],profit(be,en-1,year+1)+year*a[en]));
}
