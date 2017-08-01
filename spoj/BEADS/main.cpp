#include <bits/stdc++.h>

using namespace std;
void lmsr(string s);
int main()
{


    {
        string s;
        cin>>s;
        lmsr(s);
    }
}
void lmsr(string s)
{
    int l=s.length();
    string concat=s+s;int k;

    string arr[l];string b[l];int i;
    for( i=0;i<l;i++)
        {
            arr[i]=concat.substr(i,l);b[i]=concat.substr(i,l);
        }
    stable_sort(arr,arr+l);
    for(i=0;i<l;i++)
    {
       if(arr[0]==b[i])
       {
           k=i;break;
       }
    }

    cout<<k<<endl;
}
