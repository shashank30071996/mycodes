#include <bits/stdc++.h>

using namespace std;
void addEdge(list<int>adj[],int u,int v);
void bfsearch(list<int>adj[],int s,int v);
int main()
{
    cout << "Hello world!" << endl;
    int v;cin>>v;
    list<int>adj[v];
    addEdge(adj,0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    addEdge(adj,3, 3);
   bfsearch(adj,2,v);
    return 0;
}
void addEdge(list<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}

void bfsearch(list<int>adj[],int s,int v)
{
    vector<bool>visited(v,false);
    list<int>q;
    q.push_back(s);visited[s]=true;
    list<int>::iterator i;
    while(!q.empty())
    {    s=q.front();
        cout<<s<<"   ";
        q.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(visited[*i]==false)
            {
                q.push_back(*i);
                visited[*i]=true;
            }
        }

    }
}
