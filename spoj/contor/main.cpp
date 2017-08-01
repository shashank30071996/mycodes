#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int i=1;int j=1;int count=1;int h=0,v=0;
        while(k>count)
        {


            if(i==1 && j>=i && k>count && h==0)
            {
                j++;count++;h=1;
            }
            else if(i==1 && j>=i && k>count && h==1)
            {

                int ti=i,tj=j;//temporary
                while(i!=tj && j!=ti && k>count)
                {
                    i++;j--;count++;
                }
                v=0;
            }
           else if(j==1 && i>j && k>count && v==0)
            {
                i++;count++;v=1;
            }
           else if(j==1 && i>j && k>count && v==1)
            {
                int it=i;int jt=j;
                while(i!=1 && j!=it && k>count)
                {
                    i--;j++;count++;
                }
                h=0;
            }
        }
        if(k==count)
            printf("TERM %d IS %d/%d\n",k,i,j);
    }
}
