#include <bits/stdc++.h>
#include<bst.cpp>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string n;
    cin>>n;int l=n.length();long int t=stoi(n,nullptr,0);
    int k=0;
    if(l==1)
        k++;
    else
    {
        int i=0;int flag=0;int m=0;
        while(i<l )
        {
           if(n[i]-'0'==0 )
           {
               flag++;
           }i++;
        }

        {
            k=(int)((n[0]-48)+1)*pow(10,flag)-t;
        }


    }
    return 0;
}
