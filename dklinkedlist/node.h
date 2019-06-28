#ifndef DK_LISTNODE_H
#define DK_LISTNODE_H

namespace dk{

  template <class T>
  class ListNode{
    public:
      ListNode(const T &value): next_(nullptr),data_(value){}
      ~ListNode(){};
      ListNode &operator = (const ListNode &)=default;
      ListNode(const ListNode &)=delete;

      const T &getData() const{return data_;}
      void setDate(const T &data){data_=data;}
      ListNode<T> *getNext() const{return next_;}
      void setNext(ListNode<T> *element){next_=element;}

    private:
      ListNode<T> *next_;
      T data_;

  };
} //namespace dk

#endif //DK_LISTNODE_H
