#include "node.h"
#include <stdlib.h>
#include <iostream>

#ifndef DK_LINKEDLIST_H
#define DK_LINKEDLIST_H

namespace dk{

  template <class T>
  class LinkedList{
    public:
      explicit LinkedList(): head_(nullptr){}
      ~LinkedList();
      LinkedList(const LinkedList &) = delete;
      LinkedList &operator =(const LinkedList &) = delete;

      //Get size of linked list
      int size() const;
      //Push node to front of ListNode
      void pushFront(T value);
      //Check if list is empty
      bool isEmpty();
      //Return value of node at nth index starting from 0
      const T &valueAt(int index) const;
      //Print data stored in linked List
      void printList() const;
      //Remove front node and return it's value
      const T popFront();
      //Push item to end of linked List
      void pushBack(T value);
      //Remove end node and return it's value
      T popBack();
      //Return value of the front node
      T front();
      //Return value of the end node
      T back();
      //Insert item at index. Index start from 0
      void insertNode(int index, T value);
      //Remove node from index. Index start from 0
      void removeNode(int index);
      //Return value of nth node from the end. Last node is position 1
      T valueNFromEnd(int n);
      //Reverse items of linked List
      void reverse();
      //Remove first item in list with given value
      void removeValue(T value);

    private:
      ListNode <T> *head_;

  };

} //namespace dk

#endif //DK_LINKEDLIST_H
