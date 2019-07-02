#ifndef DK_MERGE_SORT_H
#define DK_MERGE_SORT_H

namespace dk{

  //Merge ranges in array
  void Merge(int numbers[],int low, int mid, int high);
  //Sort array between low and high indexes
  void MergeSort(int numbers[], int low, int high);

}

#endif //DK_MERGE_SORT_H
