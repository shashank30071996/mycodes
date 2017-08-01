#include<bits/stdc++.h>
using namespace std;

 int main()
{

     int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
         int n,j;long int k;
        cin>>n;cin>>k;
       long int a[n];
        for( j=0;j<n;j++)
        {
            cin>>a[j];
        } long int count=0;
        j=0;while(j<n)
        {


          long int r=a[j]%k;

            if(a[j]>k && (a[j]-r)>0)
            count=count+min(r,k-r);
            else
                count=count+(k-r);
            j++;

        }
       cout<<count<<endl;


    }
}

