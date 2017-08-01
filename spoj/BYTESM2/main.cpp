#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int t;
    cin>>t;
    while(t--)
    {
        int l,w;
        cin>>l;cin>>w;
        int a[l][w+2];memset(a,0,sizeof(a));

        int i,j;

        for(i=0;i<l;i++)
        {
            for(j=1;j<=w;j++)
                cin>>a[i][j];
        }
        for(i=l-2;i>=0;i--)
         {
        for(j=1;j<=w;j++)
         {  int k=max(a[i+1][j],max(a[i+1][j-1],a[i+1][j+1]));

            a[i][j]=a[i][j]+k;
            }
            }
        int ans=a[0][1];
        for(j=2;j<=w;j++)
        {

            if(a[0][j]>ans)
            ans=a[0][j];}
            cout<<ans<<endl;

    }
    return 0;
}
