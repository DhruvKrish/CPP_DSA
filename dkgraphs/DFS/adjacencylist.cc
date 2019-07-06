#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100];
bool visited[100]={0};

void DFS(int s, int numnodes){

  visited[s]=true;
  cout<<s<<" ";

  for(int i=0;i<adj[s].size();i++){
    int v=adj[s][i];
    if(!visited[v]){
      DFS(v, numnodes);
    }
  }
}

void AddEdge(int u, int v){
  //Add edge u->v
  adj[u].push_back(v);
}

int main(){
  cout<<"0-->1\n";
  cout<<"^  / \n";
  cout<<"| <  \n";
  cout<<"2-->3\n";
  cout<<"    '\n";

  AddEdge(0, 1);
  AddEdge(0, 2);
  AddEdge(1, 2);
  AddEdge(2, 0);
  AddEdge(2, 3);
  AddEdge(3, 3);

  for(int i=0;i<4;i++){
    if(!visited[i]){
      DFS(i, 4);
    }
  }

  return 0;
}
