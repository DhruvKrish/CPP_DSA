#include "linkedlist.h"
using namespace std;
namespace dk{

  template <class T>
  LinkedList<T>::~LinkedList(){
    ListNode<T> *current=head_;
    ListNode<T> *next=nullptr;

    while(current){
      next=current->getNext();
      delete current;
      current=next;
    }
  }

  template <class T>
  int LinkedList<T>::size() const{
    int sizelist=0;

    ListNode<T> *current=head_;
    while(current){
      sizelist++;
      current=current->getNext();
    }

    return sizelist;
  }

  template <class T>
  void LinkedList<T>::pushFront(T value){
    ListNode<T> *newnode=new ListNode<T>{value};

    newnode->setNext(head_);
    head_=newnode;
  }

  template <class T>
  bool LinkedList<T>::isEmpty(){
    if(head_==nullptr){
      return true;
    }
    else{
      return false;
    }
  }

  template <class T>
  const T& LinkedList<T>::valueAt(int index) const{
    //Use of c++11 auto
    auto current=head_;

    for(int i=0;i<index;i++){
      current=current->getNext();
    }

    return current->getData();
  }

  template <class T>
  void LinkedList<T>::printList() const{
    ListNode<T> *current=head_;

    while(current!=nullptr){
      cout<<current->getData()<<"->";
      current=current->getNext();
    }
    cout<<"NULL"<<endl;
  }

  template <class T>
  const T LinkedList<T>::popFront(){
     auto current=head_->getNext();

    const T value=head_->getData();

    delete head_;
    head_=current;

    return value;
  }

  template <class T>
  void LinkedList<T>::pushBack(T value){
    ListNode<T> *newnode=new ListNode<T>{value};
    auto current=head_;

    while(current->getNext()!=nullptr){
    }
    current->setNext(newnode);
  }

  template <class T>
  T LinkedList<T>::popBack(){
    auto current=head_;

    while(current->getNext()->getNext()!=nullptr){
    }
    T value=current->getNext()->getData();

    delete current->getNext();
    return value;
  }

  template <class T>
  T LinkedList<T>::front(){
    return head_->getData();
  }

  template <class T>
  T LinkedList<T>::back(){
    auto current=head_;

    while(current->getNext()!=nullptr){

    }
    return current->getData();
  }

  template <class T>
  void LinkedList<T>::insertNode(int index,T value){
    ListNode<T> * newnode=new ListNode<T>{value};
    auto current=head_;

    for(int i=0;i<index-1;i++){
      current=current->getNext();
    }
    newnode->setNext(current->getNext());
    current->setNext(newnode);

  }

  //Take care of head case
  template <class T>
  void LinkedList<T>::removeNode(int index){
    if(index==0){
      popFront();
      return;
    }

    auto current=head_;

    for(int i=0;i<index-1;i++){
      current=current->getNext();
    }
    auto newnextnode=current;
    newnextnode=newnextnode->getNext()->getNext();

    delete current->getNext();
    current->setNext(newnextnode);
  }

  template <class T>
  T LinkedList<T>::valueNFromEnd(int n){
    auto current=head_;
    int sizelist=size();

    for(int i=0;i<sizelist-n;i++){
      current=current->getNext();
    }
    return current->getData();
  }

  //Edge cases addition
  template <class T>
  void LinkedList<T>::removeValue(T value){
    auto current=head_;
    int index=0;
    while(current){
      if(current->getData()==value){
        cout<<"removing\n";
        removeNode(index);
        break;
      }
      current=current->getNext();
      index++;
    }
  }

  template <class T>
  void LinkedList<T>::reverse(){
    auto current=head_;
    ListNode<T> *prev=nullptr;
    ListNode<T> *nextnode=nullptr;

    while(current){
      nextnode=current->getNext();
      current->setNext(prev);
      prev=current;
      current=nextnode;
    }
    head_=prev;
  }

} //namespace dk

int main(){
  cout<<"HHI"<<endl;

  dk::LinkedList<int> *test=new dk::LinkedList<int>();
  test->pushFront(2);
  test->pushBack(3);
  test->insertNode(1,1);
  cout<<test->valueNFromEnd(3)<<endl;
  test->printList();
  //test->removeValue(2);
  //cout<<test->popBack()<<endl;
  test->printList();
  test->reverse();
  test->printList();
  //cout<<test->front()<<endl;

  return 0;
}
