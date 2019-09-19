#include <iostream>
#include <list>
using namespace std;

class Graph{
  //Number of vertices
  int V;

  //pointer to adjacencylist
  list<int> *adj;

  //pointer to visited array
  bool *visited;

public:
  //Constructor
  Graph(int V);

  //Depth First search on node s
  void DFS(int s);

  //Add edge to Graph
  void AddEdge(int u, int v);

};

Graph::Graph(int V){
  this->V=V;
  adj=new list<int>[V];
  visited=new bool[V];

  for(int i=0;i<V;i++){
    visited[i]=false;
  }
}

void Graph::AddEdge(int u, int v){
  adj[u].push_back(v);
}

void Graph::DFS(int s){
  visited[s]=true;
  cout<<s<<" ";

  list<int>::iterator i;
  for(i=adj[s].begin();i!=adj[s].end();i++){
    if(!visited[*i]){
      DFS(*i);
    }
  }
}

int main(){
  cout<<"0-->1\n";
  cout<<"^  / \n";
  cout<<"| <  \n";
  cout<<"2-->3\n";
  cout<<"    '\n";

  Graph g(4);

  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 0);
  g.AddEdge(2, 3);
  g.AddEdge(3, 3);

  g.DFS(0);

  return 0;
}
