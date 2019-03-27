#ifndef __SORTING__

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void insertionSort(int *A, int n);
int partition(int *A, int l, int r);
void quickSort(int *A, int l, int r);
void countingSort(int *A, int *B, int k,int n);
void radixSort(int * array, int size);
void bucketSort(int *A, int n);

#endif // __SORTING__
