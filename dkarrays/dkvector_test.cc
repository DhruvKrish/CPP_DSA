#include "dkvector_test.h"
#include <iostream>

namespace dk {

void dkVectorTest::RunTests() const {
  TestSize();
  TestIsEmpty();
  TestCapacity();
  TestGetValueAt();
  TestPop();
  TestInsert();
  TestDelete();
  TestRemove();
  TestFind();
};

void dkVectorTest::TestSize() const{
  dk::dkVector tester(3);
  assert(tester.GetSize()==0);

  int items_to_add = 5;
  for (int i = 0; i < items_to_add; ++i) {
    tester.PushBack(i + 1);
  }
  assert(tester.GetSize() == items_to_add);
}

void dkVectorTest::TestIsEmpty() const {
  dk::dkVector tester(3);
  assert(tester.IsEmpty());
}

void dkVectorTest::TestCapacity() const {
  dk::dkVector tester(4);

  // test increasing size
  assert(tester.GetCapacity() == dk::kMinCapacity);
  for (int i = 0; i < 17; ++i) {
    tester.PushBack(i + 1);
  }
  assert(tester.GetCapacity() == dk::kMinCapacity * 2);
  for (int j = 0; j < 20; ++j) {
    tester.PushBack(j + 1);
  }

  assert(tester.GetCapacity() == dk::kMinCapacity * 4);

  // test decreasing size
  for (int k = 0; k < 30; ++k) {
    tester.Pop();

  }

  assert(tester.GetCapacity() == dk::kMinCapacity * 2);

  for (int k = 0; k < 7; ++k) {
    tester.Pop();
  }
  assert(tester.GetCapacity() == dk::kMinCapacity);
}

void dkVectorTest::TestGetValueAt() const {
  dk::dkVector tester(3);
  tester.PushBack(4);
  tester.PushBack(9);
  tester.PushBack(12);
  assert(tester.GetValueAt(0) == 4);
  assert(tester.GetValueAt(1) == 9);
  assert(tester.GetValueAt(2) == 12);
}

void dkVectorTest::TestPop() const {
  dk::dkVector tester(1);
  tester.PushBack(3);
  int popped = tester.Pop();
  assert(popped == 3);
  tester.PushBack(9);
  tester.PushBack(8);

  assert(tester.GetSize() == 2);
  int popped2 = tester.Pop();
  assert(popped2 == 8);
  assert(tester.GetSize() == 1);
}

void dkVectorTest::TestInsert() const {
  dk::dkVector tester(3);
  tester.PushBack(5);
  tester.PushBack(7);
  tester.PushBack(9);
  tester.Insert(0, 4);
  assert(tester.GetValueAt(0) == 4);
  assert(tester.GetValueAt(1) == 5);
  assert(tester.GetValueAt(2) == 7);
  assert(tester.GetValueAt(3) == 9);
  tester.Insert(3, 8);
  assert(tester.GetValueAt(3) == 8);
  assert(tester.GetValueAt(4) == 9);
}

void dkVectorTest::TestPrepend() const {
  dk::dkVector tester(3);
  tester.PushBack(9);
  tester.PushBack(8);
  tester.PushBack(7);
  tester.Prepend(6);
  assert(tester.GetSize() == 4);
  assert(tester.GetValueAt(0) == 6);
  assert(tester.GetValueAt(1) == 9);
  assert(tester.GetValueAt(3) == 7);
}

void dkVectorTest::TestDelete() const {
  dk::dkVector tester(1);
  tester.PushBack(5);
  tester.Delete(0);
  assert(tester.GetSize() == 0);

  tester.PushBack(9);
  tester.PushBack(10);
  tester.PushBack(11);
  tester.Delete(1);
  assert(tester.GetSize() == 2);
  assert(tester.GetValueAt(0) == 9);
  assert(tester.GetValueAt(1) == 11);
}

void dkVectorTest::TestRemove() const {
  dk::dkVector tester(5);
  tester.PushBack(50);
  tester.PushBack(2);
  tester.PushBack(50);
  tester.PushBack(4);
  tester.PushBack(50);
  tester.Remove(50);
  assert(tester.GetSize() == 2);
  assert(tester.GetValueAt(0) == 2);
  assert(tester.GetValueAt(1) == 4);
}

void dkVectorTest::TestFind() const {
  dk::dkVector tester(3);
  tester.PushBack(4);
  tester.PushBack(7);
  tester.PushBack(11);
  assert(tester.Find(5) == -1);
  assert(tester.Find(4) == 0);
  assert(tester.Find(7) == 1);
  assert(tester.Find(11) == 2);
}

} //namespace dk
