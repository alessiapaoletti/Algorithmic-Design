#ifndef __SORTING__
#define __SORTING__

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void insertionSort(int *A, int n);
void insertionSortbegin(int *A, int begin, int n);
void quickSort(int *A, int l, int r, int pivot);
void countingSort(int *A, int *B, int k,int n);
void radixSort(int * array, int size);
void bucketSort(double *A, int n);
int partitionPivot(int *A, int l, int r,int pivot);
Node* bubbleSort(Node *start); //used to order in bucketSort

#endif // __SORTING__
