#include<iostream>
using namespace std;

int main()
{
    cout<<"enter"<<endl;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k,j;
        cin>>n,k;

        int a[n];
        for( j=0;j<n;j++)
        {
            cin>>a[j];
        } int count=0;
        j=0;while(j<n)
        {
            int aux=a[j];
           int r=aux%k;
            if(r<=k-r)
               count=count+r;
            else
                count=count+(k-r);
                j++;
        }
       cout<<count<<endl;


    }
}

