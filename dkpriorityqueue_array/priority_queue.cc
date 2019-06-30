#include "priority_queue.h"

namespace dk{

  PriorityQueue::PriorityQueue(const int size){
    assert(size>0 && size<INT_MAX);

    elements_=new PQElement[size];
    capacity_=size;
  }

  PriorityQueue::~PriorityQueue(){
    delete[] elements_;
  }

  void PriorityQueue::Insert(const int key, const int value){
    if(size_==capacity_){
      std::cout<<"Priority Queue is full\n";
      return;
    }

    elements_[size_].key_=key;
    elements_[size_].value_=value;

    size_++;

    SiftUp(size_-1);
  }

  void PriorityQueue::SiftUp(int index){

    assert(index>=0 && index<size_);

    int parent;
    while(index > 0){
      parent = (index - 1)/2;

      if(elements_[parent].value_ < elements_[index].value_){
        Swap(parent,index);
      }
      else{
        break;
      }

      index=parent;
    }
  }

  void PriorityQueue::Swap(int index1, int index2){
    elements_[index1].key_+=elements_[index2].key_;
    elements_[index1].value_+=elements_[index2].value_;

    elements_[index2].key_=elements_[index1].key_-elements_[index2].key_;
    elements_[index2].value_=elements_[index1].value_-elements_[index2].value_;

    elements_[index1].key_-=elements_[index2].key_;
    elements_[index1].value_-=elements_[index2].value_;
  }

  void PriorityQueue::PrintDebug(){

    for(int i=0 ; i<size_; i++){
      std::cout<<elements_[i].key_<<":"<<elements_[i].value_<<" ";
    }
    std::cout<<"------------"<<std::endl;
  }

  PQElement* PriorityQueue::GetMax(){

    if(size_==0){
      return nullptr;
    }

    return &(elements_[0]);
  }

  int PriorityQueue::GetSize(){

    return size_;
  }

  bool PriorityQueue::IsEmpty(){

    return (size_==0);
  }

  PQElement* PriorityQueue::ExtractMax(){

    if(IsEmpty()){
      std::cout<<"Priority Queue is empty"<<std::endl;
      return nullptr;
    }

    PQElement* out=new PQElement;
    out->key_=elements_[0].key_;
    out->value_=elements_[0].value_;

    Swap(0,size_-1);
    SiftDown(0);

    size_--;

    return out;
  }

  void PriorityQueue::SiftDown(int index){

    std::cout<<"Sift: Index:"<<index<<" Size:"<<size_<<std::endl;
    assert(index>=0 && index<size_);

    while(index*2 + 1 < size_){
      int left_index= (index*2 + 1);
      int right_index= (index*2 + 2);
      int swap_index=index;
      bool valid_left_index=left_index<size_;
      bool valid_right_index=right_index<size_;

      if(valid_left_index && valid_right_index){
        if(elements_[left_index].value_>=elements_[right_index].value_){
          swap_index=left_index;
        }
        else{
          swap_index=right_index;
        }
      }
      else if(valid_left_index){
        swap_index=left_index;
      }
      else if(valid_right_index){
        swap_index=right_index;
      }
      else{
        break;
      }

      if(elements_[swap_index].value_>elements_[index].value_){
        Swap(index, swap_index);
        index=swap_index;
      }
      else{
        break;
      }
    }
  }

  void PriorityQueue::Remove(int index){

    assert(index>=0 && index<size_);

    Swap(index, size_-1);

    SiftDown(index);

    size_--;
  }

  void BuildMaxHeap(int *array, int count){
    for(int i=count/2-1; i>=0; i--){
      Heapify(array, count, i);
    }
  }

  void HeapSort(int *numbers, int count){
    for(int i=count-1;i>0;i--){
      numbers[0]+=numbers[i];
      numbers[i]=numbers[0]-numbers[i];
      numbers[0]-=numbers[i];

      Heapify(numbers, i, 0);
    }
  }

  void Heapify(int *numbers, int count, int index){
    assert(index>=0 && index<count);

    while(index*2 + 1 < count){
      int left_index= (index*2 + 1);
      int right_index= (index*2 + 2);
      int swap_index=index;
      bool valid_left_index=left_index<count;
      bool valid_right_index=right_index<count;

      if(valid_left_index && valid_right_index){
        if(numbers[left_index]>=numbers[right_index]){
          swap_index=left_index;
        }
        else{
          swap_index=right_index;
        }
      }
      else if(valid_left_index){
        swap_index=left_index;
      }
      else if(valid_right_index){
        swap_index=right_index;
      }
      else{
        break;
      }

      if(numbers[swap_index]>numbers[index]){
        numbers[swap_index]+=numbers[index];
        numbers[index]=numbers[swap_index]-numbers[index];
        numbers[swap_index]-=numbers[index];

        index=swap_index;
      }
      else{
        break;
      }
    }
  }

} //namespace dk
