#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/utility.h"
#include "../include/sorting.h"
#include "../include/select.h"
#include "../include/heap.h"

#define NUM_SIZE 5

int main() {
  struct timespec b_time, e_time;

  double insertion, bestinsertion, badinsertion;
  double quicksort, badquick, bestquick;
  double counting, radix, bucket;
  double heapmin, heapmax;
  int num;
  int size[NUM_SIZE] = {10000,20000,40000,80000,90000};

  //int size[NUM_SIZE] = {100000,200000,400000,800000,1000000,1200000};
  printf("Size\t InsertionSort\t BadInsertion\t BestInsertion\t QuickSort\t BadQuick\t BestQuick\t CountingSort\t RadixSort\t BucketSort\t HeapSortMin\t HeapSortMax\t\n");
  for (size_t j = 0; j < NUM_SIZE; j++) {
    int n = size[j];

    int *insertionArray = (int *) malloc(sizeof(int) * n);
    int *badInsertion = (int *) malloc(sizeof(int) * n);
    int *bestInsertion = (int *) malloc(sizeof(int) * n);

    int *quickArray = (int *) malloc(sizeof(int) * n);
    int *badQuicksort = (int *) malloc(sizeof(int) * n);
    int *bestQuick = (int *) malloc(sizeof(int) * n);

    int *countArray = (int *) malloc(sizeof(int) * n);
    int *radixArray = (int *) malloc(sizeof(int) * n);
    int *sourceHMax = (int *) malloc(sizeof(int) * n);
    int *sourceHMin = (int *) malloc(sizeof(int) * n);

    double *bucketArray = (double *) malloc (sizeof(double) *n);  //bucketSort is for value [0,1]

    srand(time(NULL));
    for (int i=0; i<n; i++){
      num = rand() % 100;
      insertionArray[i] = num;
      quickArray[i] = num;
      countArray[i] = num;
      radixArray[i] = num;
      sourceHMax[i] = num;
      sourceHMin[i] = num;
    }

    /******* Insertion Sort *******/
    clock_gettime(CLOCK_REALTIME, &b_time);
    insertionSort(insertionArray,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    insertion = get_execution_time(b_time,e_time);
    free(insertionArray);

    /* The worst case is an array ordered in descending order */
    descreasingArray(badInsertion,n);
    clock_gettime(CLOCK_REALTIME, &b_time);
    insertionSort(badInsertion,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    badinsertion = get_execution_time(b_time,e_time);
    free(badInsertion);

    /* The best case is an array ordered in ascending order */
    increasingArray(bestInsertion,n);
    clock_gettime(CLOCK_REALTIME, &b_time);
    insertionSort(bestInsertion,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    bestinsertion = get_execution_time(b_time,e_time);
    free(bestInsertion);


    /******* QuickSort *******/
    /* For the average case choose as pivot the last element of the array */
    int pivot = quickArray[n-1];
    clock_gettime(CLOCK_REALTIME, &b_time);
    quickSort(quickArray,0,n,pivot);
    clock_gettime(CLOCK_REALTIME, &e_time);
    quicksort = get_execution_time(b_time,e_time);
    free(quickArray);


    /*The worst case is when at each partition one part of the subarray is of size n-1
    We create an ordered array (both increasing or decreasing is fine) and choose as pivot the last element  */
    increasingArray(badQuicksort,n);
    pivot = badQuicksort[n-1];
    clock_gettime(CLOCK_REALTIME, &b_time);
    quickSort(badQuicksort,0,n,pivot);
    clock_gettime(CLOCK_REALTIME, &e_time);
    badquick = get_execution_time(b_time,e_time);
    free(badQuicksort);


    /*The best case is when each time the subarray have size n/2,
    we create an ordered array and choose as pivot the middle element  */
    increasingArray(bestQuick,n);
    pivot = bestQuick[n/2];
    clock_gettime(CLOCK_REALTIME, &b_time);
    quickSort(bestQuick,0,n,pivot);
    clock_gettime(CLOCK_REALTIME, &e_time);
    bestquick = get_execution_time(b_time,e_time);
    free(bestQuick);


    /******* CountingSort *******/
    int auxiliar_array[n];
    initArray(auxiliar_array,n);
    int max = findMaxArray(countArray,n);
    clock_gettime(CLOCK_REALTIME, &b_time);
    countingSort(countArray,auxiliar_array,max,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    counting = get_execution_time(b_time,e_time);
    free(countArray);


    /******* RadixSort *******/
    clock_gettime(CLOCK_REALTIME, &b_time);
    radixSort(radixArray,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    radix = get_execution_time(b_time,e_time);
    free(radixArray);

    /******* BucketSort *******/
    for (int i=0; i<n; i++)  bucketArray[i] = ((double) rand()/(RAND_MAX));
    clock_gettime(CLOCK_REALTIME, &b_time);
    bucketSort(bucketArray,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    bucket = get_execution_time(b_time,e_time);
    free(bucketArray);

    /******* HeapSort *******/
    clock_gettime(CLOCK_REALTIME, &b_time);
    heapSortMin(sourceHMin,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    heapmin = get_execution_time(b_time,e_time);
    free(sourceHMin);

    clock_gettime(CLOCK_REALTIME, &b_time);
    heapSortMax(sourceHMax,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    heapmax = get_execution_time(b_time,e_time);
    free(sourceHMax);

    /******* Print the execution times *******/
    printf("%d\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t\n",
      n,insertion,badinsertion,bestinsertion,quicksort,badquick,bestquick,counting,radix,bucket,heapmin,heapmax);
    }


  return 0;
}
