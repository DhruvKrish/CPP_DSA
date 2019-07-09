#include <iostream>
#include <vector>
using namespace std;

#define WHITE -1 //color[index] is white if node has not been visited
#define GREY 0 //color[index] is grey if node is being visited
#define BLACK 1 //color[index] is black if node has finished being visited

vector<int> adj[100];
int color[100];
int parent[100];
int cycleflag=0;

void DFS(int s){
  color[s]=GREY; //s is currently being visited
  cout<<"Visiting:"<<s<<endl;
  for(int i=0; i<adj[s].size();i++){

    int v=adj[s][i];

    if(color[v]==WHITE){ //Tree edge
      parent[v]=s;
      DFS(v);
    }
    else if(color[v]==GREY && v!=parent[s]){ //Cycle Here (Back edge)
                                             //If v==parent[s] then s,v are bidirectional
      cycleflag=1;
      cout<<"Back edge: "<<s<<"->"<<v<<endl;
    }
    //color[v]==BLACK implies s,v is a forward/cross edge
    //Can find if forward by recursively trying to find s in parent until a node reoccurs
    //If a node reoccurs during parent search, then cross edge
  }
  color[s]==BLACK;
}

void AddEdge(int u, int v){
  //Add edge u->v
  adj[u].push_back(v);
}

int main(){
  for(int i=0;i<100;i++){
    color[i]=WHITE;
  }

  cout<<"0-->1\n";
  cout<<"^  / \n";
  cout<<"| <  \n";
  cout<<"2-->3\n";
  cout<<"    '\n";

  AddEdge(0, 1);
  AddEdge(1, 2);
  AddEdge(2, 0);
  AddEdge(2, 3);
  AddEdge(3, 3);

  DFS(0);

  if(cycleflag==1){
    cout<<"Cycle Exists"<<endl;
  }
  else{
    cout<<"No Cycle"<<endl;
  }

  return 0;
}
