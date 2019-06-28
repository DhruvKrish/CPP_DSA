#include "queue_linkedlist.h"

namespace dk{

template <class T>
Queue_ll<T>::~Queue_ll(){
  ListNode<T> *current = head_;
  ListNode<T> *temp=head_;

  while(current){
    temp=current;
    current=current->getNext();
    delete temp;
  }
}

template <class T>
void Queue_ll<T>::Enqueue(T value){
  auto temp=new ListNode<T>(value);

  if(Empty()){
    head_=tail_=temp;
  }
  else{
    tail_->setNext(temp);
    tail_=temp;
  }
}

template <class T>
bool Queue_ll<T>::Empty() const{
  return head_==nullptr;
}

template <class T>
const T Queue_ll<T>::Dequeue(){
  if(Empty()){
    std::cerr << "Queue is empty. Hence, cannot dequeue" << '\n';
    exit(EXIT_FAILURE);
  }

  T value=head_->getData();

  ListNode<T> * temp=head_;

  //Case where queue has only one element
  if(head_==tail_){
    tail_=nullptr;
  }

  head_=head_->getNext();
  delete temp;

  return value;
}

template <class T>
void Queue_ll<T>::PrintQueue() const{
  ListNode<T> *current=head_;

  std::cout<<"Queue: ";

  while(current){
    std::cout<<current->getData()<<" < ";
    current=current->getNext();
  }
  std::cout<<std::endl;
}

} //namespace dk

int main(){

  std::cout<<"Queue using linked list tests:\n";

  dk::Queue_ll<int> *test=new dk::Queue_ll<int>();
  std::cout<<test->Empty()<<std::endl;
  test->Enqueue(1);
  std::cout<<test->Empty()<<std::endl;
  test->PrintQueue();
  test->Enqueue(2);
  test->PrintQueue();
  test->Enqueue(3);
  test->PrintQueue();
  std::cout<<test->Dequeue()<<"\n";
  test->PrintQueue();

  return 0;
}
