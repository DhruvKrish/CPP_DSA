#include "hash_table.h"

namespace dk{

HashTable::HashTable(const int size){
  size_=size;
  data_=new HashObject[size];

  assert(data_!=nullptr);

  for(int i=0;i<size;i++){
    data_[i].SetKey(HashObject::GetNullKey());
  }
}

HashTable::~HashTable() {delete[] data_;}

int HashTable::Hash(const std::string key){
  int hash=0;

  int key_length=static_cast<int>(key.length());
  for(int i=0;i<key_length;i++){
    hash=hash*31 + key[i];
  }

  return abs(hash%size_);
}

void HashTable::Add(HashObject *object){
  int index=Hash(object->GetKey());
  int original_index=index;
  int markedIndex=-1;

  bool found=false;

  while(data_[index].GetKey() != HashObject::GetNullKey()){
    if(data_[index].GetKey() == object->GetKey()){
      found=true;
      break;
    }
    else if(data_[index].GetKey() == HashObject::GetMarkingKey()){
      markedIndex=index;
    }

    index = (index+1) % size_;
    if(index == original_index){
      std::cout<<"Hash table is full"<<std::endl;
      return;
    }
  }

  if(!found && markedIndex != -1){
    index = markedIndex;
  }

  data_[index].SetKey(object->GetKey());
  data_[index].SetValue(object->GetValue());
}

bool HashTable::Exists(const std::string key){
  int index=Hash(key);
  int original_index=index;
  bool found=false;

  while(data_[index].GetKey() != HashObject::GetNullKey()){
    if(data_[index].GetKey() == key){
      found=true;
      break;
    }
    index = (index+1)%size_;
    if(index==original_index){
      break;
    }
  }

  return found;
}

void HashTable::Remove(const std::string key){
  int index=Hash(key);
  int original_index=index;

  while(data_[index].GetKey() != HashObject::GetNullKey()){
    if(data_[index].GetKey() == key){
      data_[index].SetKey(HashObject::GetMarkingKey());
      data_[index].SetValue("");
      break;
    }
    index= (index+1) % size_;
    if(index == original_index){
      std::cout<<"Key does not exist"<<std::endl;
      break;
    }
  }
}

const std::string HashTable::Get(const std::string key){
  int index=Hash(key);
  int original_index=index;

  while(data_[index].GetKey() != HashObject::GetNullKey()){
    if(data_[index].GetKey() == key){
      return data_[index].GetValue();
    }
    index= (index+1) % size_;
    if(index == original_index){
      break;
    }
  }

  return NULL;
}

void HashTable::PrintDebug(){
  for(int i=0; i<size_; i++){
    std::cout<< i <<": "<<data_[i].GetKey() << ":" <<data_[i].GetValue() << std::endl;
  }
}

}

int main(){
  dk::HashTable states(100);
  dk::HashObject tx;

  tx.SetKey("Texas");
  tx.SetValue("Austin");

  states.Add(&tx);
  if(states.Exists("Texas")){
    std::cout<<"Texas added properly"<<std::endl;
  }

  std::cout<<states.Get("Texas")<<std::endl;

  states.Remove("Texas");
  if(!states.Exists("Texas")){
    std::cout<<"Texas deleted properly"<<std::endl;
  }

  dk::HashTable colors(1);
  dk::HashObject one;
  dk::HashObject two;

  one.SetKey("one");
  one.SetValue("red");
  two.SetKey("two");
  two.SetValue("blue");

  colors.Add(&one);
  if(colors.Exists("one")){
    std::cout<<"Added one successfully"<<std::endl;
  }

  colors.Add(&two);
  if(!colors.Exists("two")){
    std::cout<<"Can't add two because hash table is full"<<std::endl;
  }

  return 0;
}
