#include <stdlib.h>
#include "utility.h"

void insertionSort(int *A, int n) {
  int i,j,key;
  for (j=1; j<n; j++){
    key = A[j];
    i = j-1;
    while (i>=0 && A[i]>key){
      A[i+1] = A[i];
      i = i-1;
    }
    A [i+1] = key;
  }
}

int partition(int *A, int l, int r){
  int pivot,i,j;
  pivot = A[r]; //choose the last element as the pivot
  i = l-1;

  for (j = l; j<= r-1; j++){
    if(A[j] <= pivot) {
      i = i+1;
      swap(&A[i],&A[j]);
    }
  }
    swap(&A[i+1],&A[r]);
    return i+1;
}

void quickSort(int *A, int l, int r){
  r = r-1; // to make the call quickSort(A,0,n) insthead of quickSort(A,0,n-1)
  int p;
  while (l<r){
    p = partition(A,l,r);
    quickSort(A,l,p-1);
    l = p+1;
    l++;
  }
}

void countingSort(int *A, int *B, int k,int n){
  int C[k];
  initArray(C,k);
  // for (size_t i = 0; i < k; i++) {
  //   C[i]=0;
  // }
  printArray(C,k);
  printf("\n");
  for (size_t j = 0; j < n; j++) {
    C[A[j]] = C[A[j]]+1;
  }
  printArray(C,k);
  printf("\n");

  for (size_t i = 1; i < k; i++) {
    C[i] = C[i] + C[i-1];
  }
  printArray(C,k);
  printf("\n");

  for (size_t j = n-1; j > 0 ; j--) {
    printf("sono dentro for %d %d  \n",  A[j], C[A[j]]-1);
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
  printArray(B,n);

}


void radixSort(int * array, int size){
  // Base 10 is used
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findMax(array, size);

  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){

    //printf("\tSorting: %d's place ", significantDigit);
    //printArray(array, size);

    int bucket[10] = { 0 };

    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;

    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    // Use the bucket to fill a "semiSorted" array
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];


    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];

    // Move to next significant digit
    significantDigit *= 10;

    //printf("\n\tBucket: ");
    //printArray(bucket, 10);
  }
}

void bucketSort(int *A, int n)
{
    int aux[n];
    for (size_t i = 0; i < n; i++)
        aux[i] = 0;

    for (size_t i = 0; i < n; i++)
        (aux[A[i]])++;

    for (size_t i = 0, j = 0; i < n; i++)
        for(; aux[i] > 0; (aux[i])--)
            A[j++] = i;
}
