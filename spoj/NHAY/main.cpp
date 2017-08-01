#include <bits/stdc++.h>
using namespace std;
void KMP(string pat,string txt,int m);
void computelps(string pat,int *lps,int m);
int main()
{
    int m;
    string pat;string txt;

    while(scanf("%d",&m)!=EOF){
    cin>>pat;
    cin>>txt;
    KMP(pat,txt,m);

    }

}
void KMP(string pat,string txt,int m)
{
    int i=0,j=0;vector<int> loc;
    int lps[m];
    computelps(pat,lps,m);int k=0;
    while(i<txt.length())
    {

        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }

        if(j==m)
           {
            printf("%d\n",i-j);
            j=lps[j-1];k=1;

            loc.push_back(i-j);
           }
           else if(i<txt.length() && pat[j]!=txt[i])
           {
               if(j!=0)
                j=lps[j-1];
               else
                i=i+1;
           }
    }
    if(k==0)
        cout<<endl;
     cout<<endl;

}

void computelps(string pat,int *lps,int m)
{

    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m)
    {
        if(pat[len]==pat[i])
        {
            len++;
            lps[i]=len;i++;
        }
        else{
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i]=0;i++;
            }
        }
    }


}

