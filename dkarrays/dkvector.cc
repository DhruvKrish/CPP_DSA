#include "dkvector.h"
#include <iostream>

namespace dk{

  dkVector::dkVector(int capacity):size_(0){
    if(capacity<1){
      std::cout<<"Vector should have a minimum capacity of 1"<<std::endl;
      exit(EXIT_FAILURE);
    }

    int actual_capacity=DetermineCapacity(capacity);
    capacity_=actual_capacity;
    data_=std::unique_ptr<int[]>(new int[capacity_]);
  }

  dkVector::dkVector(){};

  int dkVector::DetermineCapacity(int capacity) const{
    int actual_capacity=kMinCapacity;

    while(capacity>actual_capacity/kGrowthFactor){
      actual_capacity*=kGrowthFactor;
    }

    return actual_capacity;
  }

  int dkVector::GetSize() const{
    return size_;
  }

  bool dkVector::IsEmpty() const{
    return (size_==0);
  }

  int dkVector::GetCapacity() const{
    return capacity_;
  }

  void dkVector::PushBack(int value){
    ResizeIfNeeded(size_+1);

    data_[size_]=value;
    size_++;
  }

  int dkVector::GetValueAt(int index) const{
    if(index<0 || index>=size_){
      std::cout << "Index out of bounds" << std::endl;
      exit(EXIT_FAILURE);
    }
    return data_[index];
  }

  int dkVector::Pop(){
    if(this->IsEmpty()){
      std::cout<<"dkvector is empty and hence can't pop anything"<<std::endl;
      exit(EXIT_FAILURE);
    }

    ResizeIfNeeded(size_-1);
    int element=data_[size_-1];
    size_--;
    return element;
  }

  int dkVector::LookUpLast() const{
    return data_[size_-1];
  }

  void dkVector::Insert(int index,int value){
    if(index<0 || index>=size_){
      std::cout<<"Index is out of bounds"<<std::endl;
      exit(EXIT_FAILURE);
    }

    ResizeIfNeeded(size_+1);
    size_++;

    for(int i=size_-1;i>=index;i--){
      data_[i]=data_[i-1];
    }

    data_[index]=value;
  }

  void dkVector::Prepend(int value){
    this->Insert(0,value);
  }

  void dkVector::Delete(int index){
    if(index<0 || index>=size_){
      std::cout<<"Index is out of bounds";
      exit(EXIT_FAILURE);
    }

    if(this->IsEmpty()){
      std::cout<<"Can't delete anything as dkvector empty"<<std::endl;
      exit(EXIT_FAILURE);
    }

    for(int i=index;i<size_;i++){
      data_[i]=data_[i+1];
    }

    ResizeIfNeeded(size_-1);
    size_--;
  }

  int dkVector::Find(int value) const{
    for(int i=0;i<size_;i++){
      if(data_[i]==value){
        return i;
      }
    }
    return -1;
  }

  void dkVector::Remove(int value){
    while(this->Find(value)!=-1){
      Delete(this->Find(value));
    }
  }

  void dkVector::ResizeIfNeeded(int candidate_size){
    if(candidate_size>size_){
      if(size_==capacity_){ //growth required
        IncreaseCapacity();
      }
    }
    else if(candidate_size<size_){
      if(size_<capacity_/kShrinkFactor){ //shrink required
        DecreaseCapacity();
      }
    }
  }

  void dkVector::IncreaseCapacity(){
    int old_capacity=capacity_;
    int new_capacity=DetermineCapacity(capacity_);


    if(old_capacity!=new_capacity){
      std::unique_ptr<int[]> new_data_(new int[new_capacity]);

      for(int i=0;i<size_;i++){
        new_data_[i]=data_[i];
      }

      data_=std::move(new_data_);
      capacity_=new_capacity;
    }

  }

  void dkVector::DecreaseCapacity(){
    int old_capacity=capacity_;
    int new_capacity=capacity_/2;

    if(new_capacity<kMinCapacity){
      new_capacity=kMinCapacity;
    }

    if(old_capacity!=new_capacity){
      std::unique_ptr<int[]> new_data(new int[new_capacity]);

      for(int i=0;i<size_;i++){
        new_data[i]=data_[i];
      }
      data_=std::move(new_data);

      capacity_=new_capacity;
    }

  }

} //namespace dk
