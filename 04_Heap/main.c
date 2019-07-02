#include "heap.h"
#include "utility.h"
#include <time.h>

#define NUM_SIZE 5

int main(){
  int n = 5;

  /******* Max Heap  *******/
  int *sourcemax = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) sourcemax[i] = n+i;
  heap maxH = buildHeap(sourcemax,n, MAX);
  printHeap(&maxH);
  int max = extractMax(&maxH);
  printf("The max is %d\n",max );
  printHeap(&maxH); //heap after extracting the max

  int oldIndex = 2;
  int newValue = 3;
  printf("\n\nIncreasing key -> from %d to %d\n", maxH.array[oldIndex], newValue);
  increaseKey(&maxH,oldIndex,newValue); //value is not bigger
  printHeap(&maxH); //no changes in the max heap

  newValue = 55;
  printf("\n\nIncreasing key -> from %d to %d\n", maxH.array[oldIndex], newValue);
  increaseKey(&maxH,oldIndex,newValue);
  printHeap(&maxH); //55 insthead 8

  int insertValue = 23;
  printf("\nAfter inserting %d \n",insertValue );
  insertHeapMax(&maxH,insertValue);
  printHeap(&maxH);

  printf("------------------------------------------------------------ \n");
  /******* Min Heap  *******/
  int *sourcemin = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) sourcemin[i] = n-i+5;
  heap minH = buildHeap(sourcemin,n, MIN);
  printHeap(&minH);
  int min = extractMin(&minH);
  printf("The min is %d\n",min );
  printHeap(&minH); //heap after extracting the min

  newValue = 3;
  printf("\n\nDecreasing key -> from %d to %d\n", minH.array[oldIndex], newValue);
  decreaseKey(&minH,oldIndex,newValue);
  printHeap(&minH); //3 insthead 8

  newValue = 55;
  printf("\n\nDecreasing key -> from %d to %d\n", minH.array[oldIndex], newValue);
  decreaseKey(&minH,oldIndex,newValue); //value is not smaller
  printHeap(&minH);

  insertValue = 1;
  printf("\nAfter inserting %d \n",insertValue );
  insertHeapMin(&minH, insertValue); //insert number 1
  printHeap(&minH);

  printf("------------------------------------------------------------ \n");

  /******* HeapSort  *******/
  struct timespec b_time, e_time;
  double heapmin, heapmax;
  int size[NUM_SIZE] = {10000,50000,70000,100000,150000};
  printf("\nSize\t HeapSortMin\t HeapSortMax\n");
  for (int j = 0; j < NUM_SIZE; j++) {
    int n = size[j];
    int num;
    int sourceMax[n], sourceMin[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
      num = rand() %100;
      sourceMax[i] = num;
      sourceMin[i] = num;
    }

    clock_gettime(CLOCK_REALTIME, &b_time);
    heapSortMin(sourceMin,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    heapmin = get_execution_time(b_time,e_time);

    clock_gettime(CLOCK_REALTIME, &b_time);
    heapSortMax(sourceMax,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    heapmax = get_execution_time(b_time,e_time);

    printf("%d\t %lf\t %lf\n", n,heapmin,heapmax);
  }
  return 0;
}
