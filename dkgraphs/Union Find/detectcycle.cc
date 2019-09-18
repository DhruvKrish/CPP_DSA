#include <iostream>
#include <vector>
using namespace std;

//Adjacency list base array
vector<int> adj[100];

int findparent(int parent[], int i){
  if(parent[i]==-1){
    return i;
  }
  else{
    return(parent, parent[i]);
  }
}

void Union(int parent[], int x, int y){
  int xparent=findparent(parent, x);
  int yparent=findparent(parent, y);


  if(xparent!=yparent){
    parent[xparent]=yparent;
    //cout<<"yparent:"<<yparent<<endl;
  }
}

bool hasCycle(int numnodes){
  int parent[numnodes];
  for(int i=0;i<numnodes;i++){
    parent[i]=-1;
  }

  for(int i=0;i<numnodes;i++){
    for(int j=0;j<adj[i].size();j++){
      int x=findparent(parent,i);int y=findparent(parent,adj[i][j]);

      if(x==y) {cout<<i<<"->"<<adj[i][j]<<" "<<"Parent:"<<x<<endl; return true;}

      Union(parent, x, y);
    }
  }

  return false;

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

  if(hasCycle(5)){
    cout<<"Cycle"<<endl;
  }
  else{
    cout<<"No Cycle"<<endl;
  }

  return 0;
}
