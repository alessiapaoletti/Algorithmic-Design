#ifndef __HEAP__
#define __HEAP__
#include <stdlib.h>
#include<stdio.h>

struct heap {
  int *array;
  int size;
  enum {MIN,MAX} type;//0 min, 1 max
};
typedef struct heap heap;

void printHeap(heap *A);
void maxHeapify(int *a, int i, int heapsize);
heap buildMaxHeap(int *sourceArray, int n, int type);
int is_valid_node(heap* H, size_t i);
void swapHeap(heap* hp, size_t i, size_t m);
int extractMax(heap *H);
void heapSortMax(int * array, int n);
void heapSortMin(int * array, int n);
void minHeapify(heap *H, size_t i);
heap buildMinHeap(int *sourceArray, int n, int heapType);
int extractMin(heap *H);
int parent(int i);
size_t left (size_t i);
size_t right (size_t i);
int is_valid_node(heap* H, size_t i);
int findMax(heap *H);
int findMin(heap *H);
int getRoot();
int isRoot(int i);
void decreaseKey(heap *H, int i, int value);
void increaseKey(heap *H, int i, int value);
heap buildHeap(int *sourceArray, int n, int heapType);
void insertHeapMin(heap *H, int value);
void insertHeapMax(heap *H, int value);


#endif //__HEAP__
