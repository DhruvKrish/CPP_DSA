#include "bst.h"

namespace dk{

BSTNode* GetNewNode(int value){
  BSTNode* node = new BSTNode;
  node->data=value;
  node->left=nullptr;
  node->right=nullptr;

  return node;
}

BSTNode* BSTNodeExists(BSTNode* node, int value){

  if(node==nullptr){
    return node;
  }
  else if(value > node->data){
    return BSTNodeExists(node->right, value);
  }
  else if(value < node->data){
    return BSTNodeExists(node->left, value);
  }
  else{
    return node;
  }
}

BSTNode* Insert(BSTNode * node, int value){

  if(node==nullptr){
    node=GetNewNode(value);
    return node;
  }

  if(value >= node->data){
    node->right=Insert(node->right, value);
  }
  else if(value < node->data){
    node->left=Insert(node->left, value);
  }

  return node;
}

void DeleteTree(BSTNode* node){
  if(node==nullptr){
    return;
  }

  if(node->left!=nullptr){
    DeleteTree(node->left);
  }
  if(node->right!=nullptr){
    DeleteTree(node->right);
  }
  delete node;
}

int GetMin(BSTNode* node){
  if(node==nullptr){
    std::cout<<"Empty in min!";
    return -1;
  }

  if(node->left!=nullptr){
    return GetMin(node->left);
  }
  else{
    return node->data;
  }
}

int GetMax(BSTNode* node){
  if(node==nullptr){
    return -1;
  }

  if(node->right!=nullptr){
    return dk::GetMax(node->right);
  }
  else{
    return node->data;
  }
}

int GetHeight(BSTNode* node){
  if(node==nullptr){
    return 0;
  }
  else{
    return 1 + std::max(GetHeight(node->left),GetHeight(node->right));
  }
}

void PrintBFS(BSTNode* node){
  std::queue<BSTNode*> nodes;
  nodes.push(node);

  BSTNode* current;

  while(!nodes.empty()){
    current=nodes.front();

    nodes.pop();

    if(current!=nullptr){
      std::cout<<current->data<<" ";
    }

    if(current->left!=nullptr){
      nodes.push(current->left);
    }
    if(current->right!=nullptr){
      nodes.push(current->right);
    }
  }
  std::cout<<std::endl;
}

void PrintInOrder(BSTNode* node){
  if(node==nullptr){
    return;
  }

   PrintInOrder(node->left);
   std::cout<<node->data<<" ";
   PrintInOrder(node->right);
}

bool IsBinarySearchTree(BSTNode* node){
  return IsBetween(node,INT_MAX,INT_MIN);
}

bool IsBetween(BSTNode* node, int max, int min){
  if(node==nullptr){
    return true;
  }

  if(node->data>min && node->data<max
    && IsBetween(node->left, node->data, min)
    && IsBetween(node->right, max, node->data)){
      return true;
  }
  else{
    return false;
  }
}

BSTNode* GetMinNode(BSTNode* node){
  if(node==nullptr){return node;}

  if(node->left!=nullptr){
    GetMinNode(node->left);
  }
  else{
    return node;
  }
}

BSTNode* DeleteValue(BSTNode* node, int value){
  if(node==nullptr){return node;}

  if(value>node->data){
    node->right=DeleteValue(node->right, value);
  }
  else if(value<node->data){
    node->left=DeleteValue(node->left, value);
  }
  else{ //node is the node to delete
    //leaf node
    if(node->left==nullptr && node->right==nullptr){
      delete node;
      node=nullptr;
    }
    //One child: right
    else if(node->left==nullptr){
      BSTNode* todelete=node;
      node=node->right;
      delete todelete;
    }
    //One child: left
    else if(node->right==nullptr){
      BSTNode* todelete=node;
      node=node->left;
      delete todelete;
    }
    //Two children
    else{
      BSTNode* toswap=GetMinNode(node->right);
      node->data=toswap->data;
      node->right=DeleteValue(node->right, toswap->data);
    }
  }
}

BSTNode* GetSuccessor(BSTNode* node, int value){
  BSTNode* value_node=BSTNodeExists(node, value);

  if(value_node==nullptr){return value_node;}

  if(value_node->right != nullptr){
    return GetMinNode(value_node->right);
  }
  else{
    //Deepest node with value_node in it's left subtree
    BSTNode* successor=nullptr;
    BSTNode* ancestor=node;
    while(ancestor!=nullptr){
      if(value < ancestor->data){
        successor=ancestor;
        ancestor=ancestor->left;
      }
      else{
        ancestor=ancestor->right;
      }
    }
    return successor;

  }
}

} //namespace dk
