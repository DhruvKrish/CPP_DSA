#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<int> adj[100];
vector<int> adjreverse[100];
bool visited[100];
stack<int> order;

void DFSreverse(int s){

  visited[s]=true;
  cout<<s<<" ";

  for(int i=0;i<adjreverse[s].size();i++){
    int v=adjreverse[s][i];
    if(!visited[v]){
      DFSreverse(v);
    }
  }
}


void orderInStack(int s){
  visited[s]=true;

  for(int i=0;i<adj[s].size();i++){
    if(!visited[adj[s][i]]){
      orderInStack(adj[s][i]);
    }
  }
  order.push(s);
  cout<<"Pushed:"<<s<<endl;
}

void reverseGraph(int numnodes){
  for(int i=0; i<numnodes; i++){
    for(int j=0; j<adj[i].size();j++){
      adjreverse[adj[i][j]].push_back(i);
    }
  }
}

void DFSUtil(){
  int source;

  while(!order.empty()){
    source=order.top();order.pop();

    if(!visited[source])
    {
      DFSreverse(source);
      cout<<endl;
    }
  }
}

//print strongly connected components of  graph
void stronglyConnectedComponents(int numnodes){

  for(int i=0;i<numnodes;i++){
    visited[i]=false;
  }

  for(int i=0;i<numnodes;i++){
    if(!visited[i]) orderInStack(i);
  }
  reverseGraph(numnodes);

  for(int i=0;i<numnodes;i++){
    visited[i]=false;
  }

  DFSUtil();
}

void AddEdge(int u, int v){
  //Add edge u->v
  adj[u].push_back(v);
}

int main(){
  cout<<"1-->0-->3-->4\n";
  cout<<"^  / \n";
  cout<<"| <  \n";
  cout<<"2\n";
  cout<<"\n";

  AddEdge(0, 2);
  AddEdge(1, 0);
  AddEdge(2, 1);
  AddEdge(0, 3);
  AddEdge(3, 4);

  cout<<"Strongly Connected Components: "<<endl;
  stronglyConnectedComponents(5);
  cout<<endl;

  return 0;
}
