#include <bits/stdc++.h>

using namespace std;
void addEdge(vector< pair<int,int> >adj[],int u,int v,int wt);
void printGraph(vector<pair<int,int> > adj[], int V);
int main()
{
    cout << "Hello world!" << endl;
    int v;
    cin>>v;
    vector< pair<int,int> > adj[v];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, v);

    return 0;
}
void addEdge(vector< pair<int,int> >adj[],int u,int v,int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (iterator  i = adj[u].begin(); i!=adj[u].end(); i++)
        {
            v = *i->first;
            w = *i->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}
