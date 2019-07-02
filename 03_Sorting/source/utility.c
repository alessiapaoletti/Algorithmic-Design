#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void copyPartialArray(int* A1 , const int*A2 , const int start, const int n){
	for (int i = start; i < start+n; i++)
    A1[i-start]=A2[i];
}

void printArray(int *A, int n){
  for (int i=0; i<n; i++) {
    printf("%d ",A[i]);
  }
  printf("\n");
}

void descreasingArray(int *A, int n ){
  A[0] = n;
  for (int i = 1; i < n; i++) {
    A[i] = A[i-1]-1;
  }
}

void increasingArray(int *A, int n ){
  for (int i = 0; i < n; i++) {
    A[i] = i;
  }
}

double get_execution_time(const struct timespec b_time, const struct timespec e_time){
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}


void swap(int *a, int *b){
   int t;
   t  = *b;
   *b = *a;
   *a = t;
}

int findMaxArray(int * A, int n ) {
  int max = A[0];
  for (int i = 1; i < n; i++) {
    if (A[i]>max)
      max = A[i];
  }
  return max;
}

void initArray(int *A, int n ){
  for (int i = 0; i < n; i++) {
    A[i]=0;
  }
}

int* copyArray(int const * src, size_t len){
   int * p = malloc(len * sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}
