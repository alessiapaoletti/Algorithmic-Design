#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

void printArray(int *A, int n){
  for (int i=0; i<n; i++) {
    printf("%d ",A[i]);
  }
  printf("\n");
}

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

void swap(int *a, int *b)
{
   int t;
   t  = *b;
   *b = *a;
   *a = t;
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

int main() {

  int n = 10;
  int array[n];
  srand(time(NULL));
  for (int i=0; i<n; i++){
    array[i] =rand() % 100;
  }
  printArray(array,n);
  insertionSort(array,n);
  printArray(array,n);

  int array2[n];
  for (int i=0; i<n; i++){
    array2[i] =rand() % 100;
  }
  printArray(array2,n);
  quickSort(array2,0,n);
  printArray(array2,n);

  return 0;
}
