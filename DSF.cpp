#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class graph
{
private:
    int V;
    list<int> *adj;
public:
    graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int v,int i)
    {
        adj[v].push_back(i);
    }
    void DFS(int x);
    void DFSUtil(int x,bool visited[]);
};

void graph::DFSUtil(int x,bool visited[])
{
    visited[x]=true;
    cout<<x<<" ";
    list<int>::iterator it;
    for(it=adj[x].begin();it!=adj[x].end();it++){
        if(!visited[*it]) DFSUtil(*it,visited);
    }
}

void graph::DFS(int x)
{
    bool *visited=new bool[V];

    for(int i=0;i<V;i++) visited[i]=false;

    DFSUtil(x,visited);

}

int main()
{
    graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);
}
