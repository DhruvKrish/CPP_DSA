#include "queue_array.h"

namespace dk{

  template <class T>
  void Queue<T>::Enqueue(T value){
    if(Full()){
      std::cerr<<"Queue is full. Hence, unable to Enqueue."<<std::endl;
      exit(EXIT_FAILURE);
    }

    data_[insert_]=value;
    insert_++;
  }

  template <class T>
  const T Queue<T>::Dequeue(){
    if(Empty()){
      std::cerr<<"Queue is empty. Nothing to Dequeue."<<std::endl;
      exit(EXIT_FAILURE);
    }

    T value=data_[0];
    for(int i=0;i<insert_-1;i++){
      data_[i]=data_[i+1];
    }
    insert_--;

    return value;
  }

  template <class T>
  bool Queue<T>::Empty() const{
    return insert_==0;
  }

  template <class T>
  bool Queue<T>::Full() const{
    return insert_==kQueueCapacity;
  }

}//namespace dk

int main(){

  std::cout<<"Testing queue array\n";

  dk::Queue<int> *test2=new dk::Queue<int>();
  std::cout<<test2->Empty()<<std::endl;
  test2->Enqueue(23);
  test2->Enqueue(45);
  std::cout<<test2->Empty()<<std::endl;
  std::cout<<test2->Dequeue()<<std::endl;
  std::cout<<test2->Dequeue()<<std::endl;
  std::cout<<test2->Dequeue()<<std::endl;

  return 0;
}
