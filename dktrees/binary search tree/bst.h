#include <queue>
#include <iostream>
#include <climits>

#ifndef DK_BINARY_SEARCH_TREE_H
#define DK_BINARY_SEARCH_TREE_H

namespace dk{

struct BSTNode{
  int data;
  BSTNode* left;
  BSTNode*  right;
};

//Return new node for BST
BSTNode* GetNewNode(int value);
//Insert value in BST and return pointer to root
BSTNode* Insert(BSTNode* node, int value);
//Check if value is in BST
BSTNode* BSTNodeExists(BSTNode* node, int value);
//Free memory allocated for BST
void DeleteTree(BSTNode* node);
//Return minimum value in BST. -1 if empty
int GetMin(BSTNode* node);
//Return maximum value in BST. -1 if empty
int GetMax(BSTNode* node);
//Return height of tree. 0 if empty
int GetHeight(BSTNode* node);
//Print nodes in BST in level order
void PrintBFS(BSTNode* node);
//Print nodes in BST in inorder
void PrintInOrder(BSTNode* node);
//Check if tree is a BST
bool IsBinarySearchTree(BSTNode* node);
//Check if all values in BST are between given values snd conform to the BST conditions
bool IsBetween(BSTNode* node, int min, int max);
//Delete a node of specific value from BST
BSTNode* DeleteValue(BSTNode* node, int value);
//Return node in BST with minimum value
BSTNode* GetMinNode(BSTNode* node);
//Return in-order successor of value
BSTNode* GetSuccessor(BSTNode* node, int value);

} //namespace dk

#endif //DK_BINARY_SEARCH_TREE_H
