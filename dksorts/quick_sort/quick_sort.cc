#include "quick_sort.h"

namespace dk{

  void QuickSort(int numbers[], int lo, int hi){

    if(hi <= lo){
      return;
    }

    srand(time(0));

    int i=lo;
    int j=hi;

    int pivot=numbers[lo + (rand()%(hi-lo))];

    while(i<=j){

      while(numbers[i]<pivot){
        i++;
      }
      while(numbers[j]>pivot){
        j--;
      }

      if(i<=j){
        if(i<j){
          numbers[i]+=numbers[j];
          numbers[j]=numbers[i]-numbers[j];
          numbers[i]-=numbers[j];
        }
        i++;
        j--;
      }
    }

    QuickSort(numbers, lo, j);
    QuickSort(numbers, i, hi);
  }

}
