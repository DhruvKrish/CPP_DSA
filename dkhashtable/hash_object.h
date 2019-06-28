#include<iostream>

#ifndef DK_HASH_OBJECT_H
#define DK_HASH_OBJECT_H

namespace dk{

  class HashObject{
    public:
      HashObject(){}
      ~HashObject(){}
      HashObject(const HashObject&) = default;

      std::string &GetKey() {return key_;}
      std::string &GetValue(){return value_;}
      static const std::string GetMarkingKey() {return "<Marked>";}
      static const std::string GetNullKey() {return "<Null";}

      void SetKey(const std::string key) {key_=key;}
      void SetValue(const std::string value) {value_=value;}
      void SetAsMarked(){
        key_=GetMarkingKey();
        value_="";
      }

    private:
      std::string key_;
      std::string value_;

  };

} //namespace dk

#endif //DK_HASH_OBJECT_H
