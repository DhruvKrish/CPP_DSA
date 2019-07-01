#include "bubble_sort.h"

namespace dk{

  void BubbleSort(int *array, int n){
    int i,j;
    bool swap;

    for(i=0;i<n-1;i++){
      swap=false;

      for(j=0;j<n-i-1;j++){
        if(array[j]>array[j+1]){
          Swap(&array[j], &array[j+1]);
          swap=true;
        }
      }
      if(!swap){
        break;
      }
    }

  }

  void Swap(int *a, int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
  }
}
