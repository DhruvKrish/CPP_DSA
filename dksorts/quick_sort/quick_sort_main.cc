#include "quick_sort.h"
#include <iostream>
#include <assert.h>

int main(){

    int to_sort[10] = {613, 55, 8721, 472, 94, 72, 74, 8, 61, 356};
    int sorted[10] = {8, 55, 61, 72, 74, 94, 356, 472, 613, 8721};

    std::cout<<"To Sort: ";
    for(int i=0;i<10;i++){
      std::cout<<to_sort[i]<<" ";
    }
    std::cout<<std::endl;

    dk::QuickSort(to_sort, 0, (sizeof(to_sort)/sizeof(int))-1);

    std::cout<<"Sorted: ";
    for(int i=0;i<10;i++){
      std::cout<<to_sort[i]<<" ";
    }
    std::cout<<std::endl;

    assert(
        std::equal(std::begin(to_sort), std::end(to_sort), std::begin(sorted)));

    return 0;
}
