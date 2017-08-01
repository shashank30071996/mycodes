#include <bits/stdc++.h>

using namespace std;
void addEdge(vector<int> adj[],int u,int v);
void dfs(vector<int>adj[],int n);
void dfsutil(vector<int>adj[],vector<bool>visited,int u);
int main()
{
    cout << "Hello world!" << endl;
    int v;
    cin>>v;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    dfs(adj,v);

    return 0;
}

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(u);
    adj[v].push_back(v);
}
void dfs(vector<int>adj[],int n)
{
    vector<bool>visited(n,false);
    for(int u=0;u<n;u++)
        if(visited[u]==false)
          dfsutil(adj,visited,u);
}

void dfsutil(vector<int>adj[],vector<bool>visited,int u)
{
    cout<<u<<" ";
    visited[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(visited[adj[u][i]]==false)
            dfsutil(adj,visited,adj[u][i]);
    }
}
