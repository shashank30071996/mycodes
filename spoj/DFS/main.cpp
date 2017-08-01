#include <bits/stdc++.h>

using namespace std;


class Graph
{
    int v;
    list<int> *adj;
    void DFSutil(int v,bool visited[]);
public:
    Graph(int v);
    void addEdge(int v,int w);
    void DFS(int v);
};
Graph::Graph(int v)
{
    this->v=v;
    adj=new list<int> [v];
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int v)
{
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    DFSutil(v,visited);
}
void Graph::DFSutil(int v,bool visited[])
{
    visited[v]=true;
    cout<<v<<"  ";
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            DFSutil(*i,visited);
    }

}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) n";
    g.DFS(1);

    return 0;
}
