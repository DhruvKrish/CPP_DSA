#include "binary_search.h"

using namespace std;

int BinarySearch(int *array, int lo, int hi, int value){
  if(hi < lo){
    return -1;
  }

  int mid = (lo + hi)/2;

  if(value < array[mid]){
    return BinarySearch(array, lo, mid-1, value);
  }
  else if(value > array[mid]){
    return BinarySearch(array, mid+1, hi, value);
  }
  else{
    return mid;
  }
}

int BinarySearchIterative(int *array, int lo, int hi, int value){
  int mid;

  while(hi >= lo){
    mid = (lo + hi)/2;

    if(value < array[mid]){
      hi=mid-1;
    }
    else if(value > array[mid]){
      lo=mid+1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

int main(){
  int arr[]={1,2,3,22, 26, 78, 45};

  cout<<BinarySearch(arr, 0, sizeof(arr)/sizeof(int), 78)<<endl;
  cout<<BinarySearchIterative(arr, 0, sizeof(arr)/sizeof(int), 78)<<endl;

  cout<<BinarySearch(arr, 0, sizeof(arr)/sizeof(int), 23)<<endl;
  cout<<BinarySearch(arr, 0, sizeof(arr)/sizeof(int), 23)<<endl;

  return 0;
}
