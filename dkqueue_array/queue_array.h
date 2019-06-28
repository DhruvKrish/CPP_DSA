#ifndef DK_QUEUE_ARRAY
#define DK_QUEUE_ARRAY

#include <iostream>

namespace dk{

  template <class T>
  class Queue{

    static const int kQueueCapacity=5;
    static const int kQueuePositions=kQueueCapacity+1;

    public:
      explicit Queue(): insert_(0) {}
      ~Queue()=default;
      Queue(const Queue&) = delete;
      Queue &operator =(const Queue&) = delete;
      //Add value to front of Queue
      void Enqueue(T value);
      //Remove value from end of Queue
      const T Dequeue();
      //Check if Queue is empty
      bool Empty() const;
      //Check if Queue is full
      bool Full() const;

    private:
      int insert_;
      T data_[kQueuePositions];
  };

}//namespace dk

#endif //DK_QUEUE_ARRAY
