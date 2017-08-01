#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string p[n];int i;int f=1,check=1;
        for( i=0;i<n;i++)
            cin>>p[i];
        sort(p,p+n);
        for(i=0;i<n-1;i++)
            {


                f=p[i+1].find(p[i]);

                if(f==0)
                {
                    check=0;break;
                }
            }
            if(check==0)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;

    }
    return 0;
}
