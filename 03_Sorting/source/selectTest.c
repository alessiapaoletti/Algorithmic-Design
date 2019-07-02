#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/utility.h"
#include "../include/select.h"
#include "../include/sorting.h"

int main() {
  int n = 12;
  int *A = (int *) malloc(sizeof(int) * n);

  /* Initialize the array */
  for (size_t i = 0; i < n; i++) {
    A[i] = n-i+10;
  }
  printf("The array is: "); printArray(A,n);

  int *C = (int*)malloc(sizeof(int)*n);
  C = copyArray(A,n);
  insertionSort(C, n);
  printArray(C,n);

  for (int i = 0; i < n; i++)
    printf("the %d-th smallest element is %d (should be %d)\n", i, A[myselect(A,i,0,n-1,n)], C[i]);

  return 0;
}
