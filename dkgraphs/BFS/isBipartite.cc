#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Adjacency list base array
vector<int> adj[100];

//Level array
int level[100];
//Check if bipartite
int color[100];

void AddEdge(int u, int v){
  //Add edge u->v
  adj[u].push_back(v);
}

//BFS graph with number of nodes n from source s.
void isBipartite(int s, int n){
  for(int i=0;i<n;i++){
    color[i]=-1;
  }



  queue<int> Q;
  Q.push(s);
  color[s]=0;
  //Source is 0th level
  level[s]=0;
  int flag=0;

  while(!Q.empty()){
    int u=Q.front();
    //cout<<u<<" ";

    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        //Check color
        if(color[v]==-1){
          if(color[u]==0){
            color[v]=1;
          }
          else{
            color[v]=0;
          }

          Q.push(v);
        }
        else{
          if(color[v]==color[u]){
            flag=1;
            break;
          }
        }

        //Considering one level after previous
        level[v]=level[u]+1;

    }
    if(flag==1){
      break;
    }

    Q.pop();
  }

  if(flag==1){
    cout<<"Not Bipartite"<<endl;
    return;
  }

  cout<<endl;
  cout<<"Bipartite"<<endl;
  for(int i=0; i<n; i++)
  {
      printf("%d to %d distance = %d\n", s, i, level[i]);
  }
}

int main()
{
  cout<<"0-->1\n";
  cout<<"^  / \n";
  cout<<"| <  \n";
  cout<<"2-->3\n";
  cout<<"    '\n";

    AddEdge(0, 1);
    //AddEdge(0, 2);
    AddEdge(1, 2);
    AddEdge(2, 0);
    AddEdge(2, 3);
    //AddEdge(3, 3);

    isBipartite(0, 4);
    return 0;
}
