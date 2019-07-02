#include <stdlib.h>
#include<stdio.h>
#include<limits.h>
#include "utility.h"

struct heap {
  int *array;
  int size;
  enum {MIN,MAX} type;//0 min, 1 max
};

typedef struct heap heap;

//for MaxHeap
int findMax(heap *H){
  return H->array[0];
}

//for MinHeap
int findMin(heap *H){
  return H->array[0];
}

int is_valid_node(heap* H, int i){
    return H->size >= i;
}

size_t right(size_t i){
    return 2*i + 2;
}
size_t left(size_t i){
    return 2*i + 1;
}

int parent(int i){
    return (i-1)/2;
}

void printHeap(heap *H){
  if (H->size == 0) {
    printf("The heap is empty\n");
    return;
  }
  if (H->type == 0) printf("This is a MinHeap: ");
  else printf("This is a MaxHeap: ");

  for (int i = 0; i < H->size; i++) {
    printf("%d\t",H->array[i] );
  }
  printf("\nThe size of the heap is: %d\n",H->size);
}

void swapHeap(heap* H, size_t i, size_t j){
    int tmp = H->array[i];
    H->array[i] = H->array[j];
    H->array[j] = tmp;
}

int getRoot(){
  return 0;
}

int isRoot(int i){
  return i == 0;
}

// for MaxHeap
void minHeapify(heap *H, size_t m){
  size_t k = -1;
  while (k!=m){
    k = m;
    int children[2] = {left(k),right(k)};
    for (size_t j = 0; j < 2; j++)
      if (is_valid_node(H, children[j]) && H->array[children[j]] <= H->array[m])
        m = children[j];
    if (k!=m)
      swapHeap(H,k,m);
  }
}

// for MaxHeap
void maxHeapify(heap *H, size_t m){
  size_t k = -1;
  while (k!=m){
    k = m;
    size_t children[2] = {left(k),right(k)};
    for (size_t j = 0; j < 2; j++)
      if (is_valid_node(H, children[j]) && H->array[children[j]] >= H->array[m])
        m = children[j];
    if (k!=m)
      swapHeap(H,k,m);
  }
}

heap buildMinHeap(int *sourceArray, int n, int heapType){
    heap H = {sourceArray, n, heapType};
    int lastParentIdx = parent(H.size-1);
    for (int i =  lastParentIdx; i >= 0; i--) {
      minHeapify(&H,i);
    }
    return H;
}

heap buildMaxHeap(int *sourceArray, int n, int heapType){
    heap H = {sourceArray, n, heapType};
    int lastParentIdx = parent(H.size-1);
    for (int i =  lastParentIdx; i >= 0; i--) {
      maxHeapify(&H,i);
    }
    return H;
}

heap buildHeap(int *sourceArray, int n, int heapType){
  if (heapType == 0) buildMinHeap(sourceArray, n, heapType);
  else if (heapType == 1) buildMaxHeap(sourceArray, n, heapType);
  else printf("Type of the heap not recognized \n");
}

//for MinHeap
int extractMin(heap *H){
  int min = H->array[0];
  H->array[0] = H->array[H->size-1];
  H->size--;
  minHeapify(H,0);
  return min;
}


//for MaxHeap
int extractMax(heap *H){
  int max = H->array[0];
  H->array[0] = H->array[H->size-1];
  H->size--;
  maxHeapify(H,0);
  return max;
}

void heapSortMax(int * array, int n){
  heap H = buildHeap(array,n,1); //buildMaxHeap , type = 1
  int aux[n];
  //printHeap(&H);
  for (int i = n; i>0; i--) {
    aux[i-1] = extractMax(&H);
  }
  for (int i = 0; i < n; i++) {
    array[i] = aux[i];
  }
}

void heapSortMin(int * array, int n){
  heap H = buildHeap(array,n,0); //buildMaxHeap , type = 1
  int aux[n];
  //printHeap(&H);
  for (int i = 0; i<n; i++) {
    aux[i] = extractMin(&H);
  }
  for (int i = 0; i < n; i++) {
    array[i] = aux[i];
  }

}

void decreaseKey(heap *H, int i, int value){
  if (H->array[i]< value) printf("The value is not smaller.\n");
  else{
    H->array[i] = value;
    while (!isRoot(i) && H->array[i]<=H->array[parent(i)]){
      swapHeap(H,i,parent(i));
      i = parent(i);
    }
  }
}

void increaseKey(heap *H, int i, int value){
  if (H->array[i]> value) printf("The value is not bigger.\n");
  else{
    H->array[i] = value;
    while (!isRoot(i) && H->array[i]>=H->array[parent(i)]){
      swapHeap(H,i,parent(i));
      i = parent(i);
    }
  }
}

void insertHeapMin(heap *H, int value){
  H->size++;
  int *aux_source = (int*)malloc(sizeof(int)*H->size);
  aux_source = copyArray(H->array,H->size);
  aux_source[H->size-1] = INT_MAX;
  free(H->array);
  H->array = aux_source;
  decreaseKey(H,H->size-1,value);
}

void insertHeapMax(heap *H, int value){
  H->size++;
  int *aux_source = (int*)malloc(sizeof(int)*H->size);
  aux_source = copyArray(H->array,H->size);
  aux_source[H->size-1] = INT_MIN;
  free(H->array);
  H->array = aux_source;
  increaseKey(H,H->size-1,value);
}
