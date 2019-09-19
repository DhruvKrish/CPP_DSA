#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[100];
bool visited[100];
stack<int> topology;

void DFSpushStack(int source){
  visited[source]=true;

  for(int j=0;j<adj[source].size();j++){
    if(!visited[adj[source][j]]){
      DFSpushStack(adj[source][j]);
    }
  }

  topology.push(source);

}

void topologicalSort(int numnodes){
  for(int i=0;i<numnodes;i++){
    visited[i]=false;
  }

  for(int i=0;i<numnodes;i++){
    if(!visited[i]){
      DFSpushStack(i);
    }
  }

  cout<<"Topological order: ";
  while(!topology.empty()){
    cout<<topology.top()<<" ";topology.pop();
  }
  cout<<endl;
}

void AddEdge(int u, int v){
  //Add edge u->v
  adj[u].push_back(v);
}

int main(){
  cout<<"5-->0<--4 \n";
  cout<<"|       | \n";
  cout<<"v       v \n";
  cout<<"2-->3-->1 \n";
  cout<<"          \n";

  AddEdge(5, 0);
  AddEdge(4, 0);
  AddEdge(5, 2);
  AddEdge(4, 1);
  AddEdge(2, 3);
  AddEdge(3, 1);

  topologicalSort(6);

  return 0;
}
