namespace dk{
  void Merge(int numbers[], int lo, int mid, int hi){
    //auxillary array to Merge
    int aux[hi-lo+1];
    int i=lo;
    int j=mid+1;
    int k=0;

    while(i<=mid && j<=hi){
      //<'='for stability
      if(numbers[i]<=numbers[j]){
        aux[k]=numbers[i];
        k++;i++;
      }
      else{
        aux[k]=numbers[j];
        k++;j++;
      }
    }

    //copy remaining indexes
    //i first for stability
    while(i<=mid){
      aux[k]=numbers[i];
      k++;i++;
    }
    while(j<=hi){
      aux[k]=numbers[j];
      k++;j++;
    }

    k--;

    //Copy sorted auxillary array to original array
    while(k>=0){
      numbers[lo+k]=aux[k];
      k--;
    }
  }

  void MergeSort(int numbers[], int lo, int hi){
    if(lo<hi){
      int mid = (lo + hi)/2;

      MergeSort(numbers, lo, mid);
      MergeSort(numbers, mid+1, hi);
      Merge(numbers, lo, mid, hi);
    }
  }
}
