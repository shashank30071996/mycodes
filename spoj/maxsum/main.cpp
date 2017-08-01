#include <bits/stdc++.h>

using namespace std;
void func(int *a,int n,int c,int z);
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];int c=0;int z=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>0)
                c=1;
            if(a[i]==0)
                z++;
        }
        func(a,n,c,z);
    }
}
void func(int *a,int n,int c,int z)
{   int sum=0;int maxsum=INT_MIN;int i;long long int k=0;
    if(c==1)
    {
       for(i=0;i<n;i++)
       {
           sum=sum+a[i];
           if(sum<0)
            sum=0;
           if(maxsum<sum)
           {
              maxsum=sum;k=0;
           }
           if(sum==maxsum)
            k++;
            if(a[i]==maxsum)
                k++;

       }
    }
    else
    {
        if(!z){
        sort(a,a+n);maxsum=a[n-1];k=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==maxsum)
                k++;
        }}
        else
        {
           int x=0; maxsum=0;k=0;for(i=0;i<=n;i++)
           {
               if(a[i]==0)x++;
               else
               {

                k=k+(((x*x)+x)/2);x=0;}

           }
        }

    }
    cout<<maxsum<<" "<<k<<endl;
}
