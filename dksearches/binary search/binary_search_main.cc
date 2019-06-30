#include "binary_search.h"

using namespace std;
using namespace dk;

int main(){
  int arr[]={1,2,3,22, 26, 78, 45};

  cout<<BinarySearch(arr, 0, sizeof(arr)/sizeof(int), 78)<<endl;
  cout<<BinarySearchIterative(arr, 0, sizeof(arr)/sizeof(int), 78)<<endl;

  cout<<BinarySearch(arr, 0, sizeof(arr)/sizeof(int), 23)<<endl;
  cout<<BinarySearch(arr, 0, sizeof(arr)/sizeof(int), 23)<<endl;

  return 0;
}
