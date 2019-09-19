#include <iostream>
#include <map>
using namespace std;

class TrieNode{
public:
  map <char,TrieNode*> children;
  int prefixes;
  bool endofword;

  TrieNode(){
    prefixes=0;
    endofword=false;
  }
};

void insert(TrieNode *root, string word){
  TrieNode *current=root;

  for(int i=0;i<word.size();i++){
    char c=word[i];

    TrieNode *node=current->children[c];

    if(!node){
      node=new TrieNode();
      current->children[c]=node;
    }
    current=node;
    current->prefixes++;
  }
  current->endofword=true;
}

bool search(TrieNode *root, string word){
  TrieNode *current=root;

  for(int i=0;i<word.size();i++){
    char c=word[i];

    TrieNode *node=current->children[c];

    if(!node){
      return false;
    }
    current=node;
  }
  return current->endofword;
}

int prefix_number(TrieNode *root, string word){
  TrieNode *current=root;

  for(int i=0;i<word.size();i++){
    char c=word[i];

    TrieNode *node=current->children[c];

    if(!node){
      return 0;
    }
    current=node;
  }
  return current->prefixes;
}

int main()
{
	TrieNode *root=new TrieNode();
	insert(root,"harshita");
	insert(root,"harsh");
	insert(root,"sharma");
	insert(root,"harry");
	cout<<prefix_number(root,"har")<<endl;
  if(search(root, "harry")){
    cout<<"harry present"<<endl;
  }
  if(!search(root, "har")){
    cout<<"har not present"<<endl;
  }
	return 0;
}
