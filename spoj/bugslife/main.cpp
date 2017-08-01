#include <bits/stdc++.h>

using namespace std;

bool isbipartite(int n,int g[][n]);
bool bipartite(int n,int g[][n],int colorarr[],int src);
int main()
{
    cout << "Hello world!" << endl;
    int sc;
    cin>>sc;
    while(sc--)
    {
        int it;const int n;
        cin>>n;cin>>it;
        int g[n+1][n+1];
        for(int i=0;i<n+1;i++)
            memset(g[i],0,sizeof(g[i]));
        while(it--)
        {
            int i,j;cin>>i;cin>>j;
            g[i][j]=1;g[j][i]=1;

        }
        if(isbipartite(n,g)==false)
        {
          cout<<"Scenario #"<<sc+1<<":"<<endl;
          cout<<"Suspicious bugs found!"<<endl;
        }
        else
        {
            cout<<"Scenario #"<<sc+1<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }
    }
    return 0;
}

bool isbipartite(int n,int g[][x])
{
    int *colorarr=new int[n+1];
    for(int i=1;i<=n;i++)
        colorarr[i]=-1;
    for(int i=1;i<=n;i++)
        if(colorarr[i]==-1)
        if(bipartite(n,g,colorarr,i)==false)
        return false;
    return true;

}
bool bipartite(int n,int g[][x],int colorarr[],int src)
{
    colorarr[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1;v<=n;v++)
        {
            if(g[u][v] && colorarr[v]=-1)
            {
                colorarr[v]=1-colorarr[u];
                q.push(v);
            }
            else if(g[u][v] && colorarr[u]==colorarr[v])
                return false;
        }
    }
    return true;
}
