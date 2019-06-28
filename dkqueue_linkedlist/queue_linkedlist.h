#include "node.h"
#include <iostream>
#ifndef DK_QUEUE_LINKEDLIST_H
#define DK_QUEUE_LINKEDLIST_H

namespace dk{

  template <class T>
  class Queue_ll{
  public:
      explicit Queue_ll(): head_(nullptr),tail_(nullptr){};
      ~Queue_ll();
      Queue_ll(const Queue_ll &) = delete;
      Queue_ll &operator = (const Queue_ll &) = delete;
      //Add value to queue
      void Enqueue(T value);
      //Remove least recent item and return item
      const T Dequeue();
      //Check if empty
      bool Empty() const;
      //Ouput queue, least recent first
      void PrintQueue() const;

  private:
    ListNode<T> *head_;
    ListNode<T> *tail_;
  };

} //namespace dk

#endif //DK_QUEUE_LINKEDLIST_H
