#include <iostream>
using namespace std;

bool adjmatrix[128][128];
bool visited[128]={false};
int numnodes;

void DFS(int s, int numnodes){
  visited[s]=true;
  cout<<s<<" ";
  for(int v=0;v<numnodes;v++){
    if(adjmatrix[s][v] && !visited[v]){
      DFS(v, numnodes);
    }
  }
}

void AddEdge(int u, int v){
  adjmatrix[u][v]=true;
}

int main(){
  for(int i=0;i<128;i++){
    for(int j=0;j<128;j++){
      adjmatrix[i][j]=false;
    }
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

  for(int i=0;i<4;i++){
    if(!visited[i]){
      DFS(i, 4);
    }
  }

  return 0;
}
