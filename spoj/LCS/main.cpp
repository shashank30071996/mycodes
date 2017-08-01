#include <bits/stdc++.h>

using namespace std;
int lcs(string a,string b,int m,int n);
int max(int n,int m);

int main()
{
    cout << "Hello world!" << endl;
    string a;string b;
    cin>>a;cin>>b;
    int m=a.length();
    int n=b.length();
    int l=lcs(a,b,m,n);
    cout<<"lcs: "<<l<<endl;

}
int lcs(string a,string b,int m,int n)
{
   int L[m+1][n+1];memset(L,0,sizeof(int)*(m+1)*(n+1));
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%d %d %d\t",i,j,L[i][j]);
            if(i==0 || j==0)
                L[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                cout<<"checked"<<endl;
                L[i][j]=1+L[i-1][j-1];
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
            printf("%d %d %d\t",i,j,L[i][j]);
        }
        cout<<"\n"<<endl;
    }
    return L[m][n];

}
int max(int n,int m){
    return ((n>m)?n:m);
}
