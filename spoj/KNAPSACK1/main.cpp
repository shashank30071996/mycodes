#include <bits/stdc++.h>

using namespace std;
int maxweight(int val[],int wt[],int n,int e);
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int e,n;
        cin>>e;cin>>n;
        int val[n];int wt[n];
        int i;
        for(i=0;i<n;i++)
            cin>>val[i];
        for(i=0;i<n;i++)
            cin>>wt[i];
        int ans =maxweight(val,wt,n,e);
        cout<<ans<<endl;
    }
    return 0;
}
//many instances
int maxweight(int val[],int wt[],int n,int e)
{
    int ans[e+1];
    int i,j,mx;int temp;
    memset(ans,0,sizeof(ans));
    for(i=1;i<=e;i++)
    {   mx=ans[i-1];
        for(j=0;j<n;j++)
        {
            if(val[j]<=i)
            {
             temp=wt[j]+ans[i-val[j]];
             mx=max(mx,temp);
            }
        }
        ans[i]=mx;
    }

    return ans[e];
}
