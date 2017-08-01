#include<bits/stdc++.h>
using namespace std;
int nine(int arr[]);
int pallindrome(int arr[]);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string num;
        cin>>num;
        int n=num.length();
        int arr[n];
        int i=0;int j=0;
        for(i=0;i<n;i++)
            a[i]=num[i]-48;
        int ni=nine(a);
        if(ni==n)
        {
            cout<<(int)pow(10,n)+1<<endl;
        }
        else if(pallindrome(a))
        {
            if(n%2!=0)
            {
                i=n/2;j=i;
                if(a[i]==9)
                {
                    a[i]=0;a[i-1]=a[i-1]+1;a[j+1]=a[i-1];
                }
                cout<<a<<endl;
            }

        }
    }
}
