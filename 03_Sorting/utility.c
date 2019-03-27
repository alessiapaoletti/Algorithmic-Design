#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void printArray(int *A, int n){
  for (int i=0; i<n; i++) {
    printf("%d ",A[i]);
  }
  printf("\n");
}

void badArray(int *A, int n ){
  A[0] = n;
  for (size_t i = 1; i < n; i++) {
    A[i] = A[i-1]-1;
  }
}

void bestArray(int *A, int n ){
  for (size_t i = 0; i < n; i++) {
    A[i] = i;
  }
}

double get_execution_time(const struct timespec b_time, const struct timespec e_time){
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}


void swap(int *a, int *b)
{
   int t;
   t  = *b;
   *b = *a;
   *a = t;
}

int findMax(int * A, int n ) {
  int max = A[0];
  for (size_t i = 1; i < n; i++) {
    if (A[i]>max)
      max = A[i];
  }
  return max;
}

void initArray(int *A, int n ){
  for (size_t i = 0; i < n; i++) {
    A[i]=0; 
  }
}
