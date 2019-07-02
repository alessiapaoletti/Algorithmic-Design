#ifndef __SORTING__
#define __SORTING__

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

struct Node {
  double value;
  struct Node * next;
};
typedef struct Node Node;


void insertionSort(int *A, int n);
void insertionSortbegin(int *A, int begin, int n); 
void quickSort(int *A, int l, int r, int pivot);
void countingSort(int *A, int *B, int k,int n);
void radixSort(int * array, int size);
void bucketSort(double *A, int n);
//int partition(int *A, int l, int r);
int partitionPivot(int *A, int l, int r,int pivot);
Node* append(Node *head, const double value);
void printBucket(Node* const head);
void swapNode(Node *a, Node *b);
Node* bubbleSort(Node *start);
double getValueList(Node * head, int j);






#endif // __SORTING__
