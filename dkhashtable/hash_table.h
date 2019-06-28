#include <assert.h>
#include <string>
#include <cstdlib>
#include "hash_object.h"

#ifndef DK_HASH_TABLE_H
#define DK_HASH_TABLE_H

namespace dk{

class HashTable{
  public:
    explicit HashTable(const int size);
    ~HashTable();
    HashTable(const HashTable&) = delete;
    HashTable &operator = (const HashTable &) = delete;

    //Add object to table (key, value pair). If key exists, update value.
    void Add(HashObject *object);
    //Check if key exists in HashTable
    bool Exists(const std::string key);
    //Remove value mapping to key
    void Remove(const std::string key);
    //Get mapped value from key
    const std::string Get(const std::string key);
    void PrintDebug();

  private:
    int size_;
    HashObject *data_;

    int Hash(const std::string key);
};

} //namespace dk

#endif //DK_HASH_TABLE_H
