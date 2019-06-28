#ifndef DK_VECTOR_H
#define DK_VECTOR_H
#include <memory>

namespace dk{

  static const int kMinCapacity = 16;
  static const int kGrowthFactor = 2;
  static const int kShrinkFactor = 4;

class dkVector{
  public:
      dkVector();
      dkVector(int capacity);

      int GetSize() const;
      bool IsEmpty() const;
      int GetCapacity() const;
      void PushBack(int value);
      int GetValueAt(int index) const;
      int Pop();
      int LookUpLast() const;
      void Insert(int index, int value);
      void Prepend(int value);
      void Delete(int index);
      void Remove(int value);
      int Find(int value) const;

  private:
    int capacity_{kMinCapacity};
    int size_{0};
    std::unique_ptr<int[]> data_;

    int DetermineCapacity(int capacity) const;
    void ResizeIfNeeded(int candidate_size);
    void IncreaseCapacity();
    void DecreaseCapacity();

};

} //namespace dk

#endif //DK_VECTOR_H
