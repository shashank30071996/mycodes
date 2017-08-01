#include <bits/stdc++.h>

using namespace std;
void lcs();void print();
char a[102];char b[102];int la;int lb;bool acheck[102];bool bcheck[102];int lc;char c[204];
int main()
{

    while(scanf("%s",a)!=EOF)
    {
        scanf("%s",b);
         la=strlen(a);lb=strlen(b);
         lcs();
         print();

    }

    return 0;
}
void lcs()
{
    int dp[la+1][lb+1];memset(dp,0,sizeof(dp));int i,j;
    memset(acheck,false,sizeof(acheck)); memset(bcheck,false,sizeof(bcheck));
    for(i=0;i<=la;i++)
    {
        for(j=0;j<=lb;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
           else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);


        }
    }
     lc=dp[la][lb];char str[lc+1];str[lc]='\0';int indx=lc;
    i=la;j=lb;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            str[indx-1]=a[i-1];indx--;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }

    i=0;j=0;
    while(i<la && j<lc)
    {
        if(a[i]==str[j])
        {
            acheck[i]=true;j++;
        }i++;
    }
    i=lb-1;j=lc-1;
    while(i>=0 && j>=0)
    {
        if(b[i]==str[j])
           {
               bcheck[i]=true;
               j--;
           }
           i--;
    }

}
void print()
{ int i,j,k;

    i=0;j=0;k=0;
    while(i<la && j<lb  )
    {
        if(bcheck[j]==true)
        {
            while(acheck[i]!=true && i<la)
            {
             c[k]=a[i];i++; k++;
            }
            c[k]=a[i];i++;k++;j++;
        }
        else
        {
            c[k]=b[j];j++;k++;
        }
    }

    while(j<lb)
    {
        c[k]=b[j];k++;j++;
    }
    while(i<la)
    {
        c[k]=a[i];k++;i++;
    }
    c[k]='\0';
    printf("%s\n",c);

}
