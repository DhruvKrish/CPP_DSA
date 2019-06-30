#include <iostream>
#include <climits>
#include <cassert>

#ifndef DK_PRIORTY_QUEUE_H
#define DK_PRIORTY_QUEUE_H

namespace dk{

  struct PQElement{
    int key_;
    int value_;
  };

  class PriorityQueue{
    public:
      explicit PriorityQueue(const int size);
      ~PriorityQueue();
      PriorityQueue(const PriorityQueue&) = delete;
      PriorityQueue& operator= (const PriorityQueue&) = delete;
      //Add given key with value to priority_queue
      void Insert(const int key, int value);
      //Print contents of the priority_queue
      void PrintDebug();
      //Return key with max value element. nullptr if priority_queue is empty
      PQElement* GetMax();
      //Return number of elements in priority_queue
      int GetSize();
      //Check if priority_queue is empty
      bool IsEmpty();
      //Return key with max value and remove it from the priority_queue
      PQElement* ExtractMax();
      //Remove the element from priority_queue with given index
      void Remove(int index);

    private:
      int size_=0;
      int capacity_;
      PQElement* elements_;
      //Propogate element up the tree until root's heap property is satisfied
      void SiftUp(int index);
      //Swap two elements with given indices
      void Swap(const int index1, const int index2);
      //Propogate element index down the tree until heap property is satisfied
      void SiftDown(int index);
  };

  //Build max heap from array
  void BuildMaxHeap(int *array, int count);
  //Sort given array with heap sort algo
  void HeapSort(int * numbers, int count);
  //SiftDown on an array
  void Heapify(int * numbers, int count, int index);

}

#endif //DK_PRIORTY_QUEUE_H
