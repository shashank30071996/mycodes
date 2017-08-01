#include <bits/stdc++.h>

using namespace std;


class Graph
{
    int V;
    list<int> *adj;
    vector<int>indegree;
public:
    Graph(int v);
    void addEdge(int v, int w);
   void all_topological_sort();
   void all_topological_sortutil(vector<int> &res,bool visited[]);
};
Graph::Graph(int v)
{
    this->V=v;
    adj=new list<int>[v];
    for (int i = 0; i < V; i++)
        indegree.push_back(0);
}
void Graph::all_topological_sort()
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=0;
    vector<int>res;
    all_topological_sortutil(res,visited);
}
void Graph::all_topological_sortutil(vector<int> &res,bool visited[])
{
    bool flag=false;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0 && !visited[i])
        {
            list<int>::iterator j;
            for(j=adj[i].begin();j!=adj[i].end();j++)
                indegree[*j]--;
            res.push_back(i);
            visited[i]=true;
            all_topological_sortutil(res,visited);

            visited[i]=false;
            res.erase(res.end()-1);
            for(j=adj[i].begin();j!=adj[i].end();j++)
            {
                indegree[*j]++;
            }
            flag=true;
        }
    }
    if (!flag)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.

    // increasing inner degree of w by 1
    indegree[w]++;
}
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "All Topological sorts\n";

    g.all_topological_sort();

    return 0;
}
