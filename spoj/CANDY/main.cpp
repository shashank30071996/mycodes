#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;int n;cin>>n;
    while(n!=-1)
    {
        int sum=0;



        {
            int a[n];int i;
            for(i=0;i<n;i++)
            {
                cin>>a[i];
                sum=sum+a[i];
            }
            int m=sum/n;
            if(sum%n==0)
            {
                sum=0;
                for(i=0;i<n;i++)
                {
                    if(a[i]>m)
                        sum=sum+a[i]-m;
                }
                cout<<sum<<endl;
            }
            else
                cout<<-1<<endl;
        }
        cin>>n;
    }
    return 0;
}
