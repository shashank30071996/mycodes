#include <bits/stdc++.h>

using namespace std;
struct suffix
{
    int index;char *suff;
};
int *buildsuffix(char *txt,int n);
void print(int *suf,int n);
int *kasai(int *suffix,int n,char txt[]);

int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {


    char txt[1001];
    scanf("%s",&txt);int n=strlen(txt);

    int *suffixarray=buildsuffix(txt,n);

    int *lcp=kasai(suffixarray,n,txt);
    int result=n-suffixarray[0];
    for(int i=1;i<n;i++)
    {
        result=result+(n-suffixarray[i])-lcp[i-1];
    }
    cout<<result<<endl;
   }
    return 0;
}
int *buildsuffix(char *txt,int n)
{
    struct suffix suffixes[n];
    for(int i=0;i<n;i++)
    {
        suffixes[i].index=i;
        suffixes[i].suff=(txt+i);

    }
    sort(suffixes,suffixes+n,cmp);
    int *suffixarray=new int [n];
    for(int i=0;i<n;i++)
        suffixarray[i]=suffixes[i].index;
    return suffixarray;
}
void print(int *suf,int n)
{
    for(int i=0;i<n;i++)
        cout<<suf[i]<<"  "<<endl;
}
int *kasai(int *suffix,int n,char txt[])
{
    int lcp[n];
    memset(lcp,0,n);
    int invsuffix[n];
    for(int i=0;i<n;i++)
        invsuffix[suffix[i]]=i;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(invsuffix[i]==n-1)
        {
            k=0;continue;
        }
        int j=suffix[invsuffix[i]+1];
        while(i+k<n && j+k<n && txt[i+k]==txt[j+k])
        k++;
        lcp[invsuffix[i]]=k;
        if(k>0)
            k--;
    }
    return lcp;


    }
