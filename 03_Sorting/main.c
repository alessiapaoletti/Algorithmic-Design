#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

#include "utility.h"
#include "sorting.h"

int main() {

  struct timespec b_time, e_time;
  double insertion, quicksort,counting,radix,bucket,badinsertion,badquick,bestinsertion,bestquick;
  int num;
  int size[5]= {10,20,30,40,50000};
  //int size[5] = {50000,70000,10000,15000,20000};
  printf("Size\t InsertionSort\t BadInsertion\t BestInsertion\t QuickSort\t BadQuick\t BestQuick\t CountingSort\t RadixSort\t BucketSort\t \n");
  for (size_t j = 0; j < 5; j++) {
    int n = size[j];
    int array1[n], array2[n],array3[n],array4[n],array5[n];
    int badInsertion[n],badQuicksort[n],bestInsertion[n],bestQuick[n];
    srand(time(NULL));
    for (size_t i=0; i<n; i++){
      num = rand() % 100;
      array1[i] = num;
      array2[i] = num;
      array3[i] = num;
      array4[i] = num;
      array5[i] = num;
    }

    clock_gettime(CLOCK_REALTIME, &b_time);
    insertionSort(array1,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    insertion = get_execution_time(b_time,e_time);

    badArray(badInsertion,n);
    clock_gettime(CLOCK_REALTIME, &b_time);
    insertionSort(badInsertion,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    badinsertion = get_execution_time(b_time,e_time);

    bestArray(bestInsertion,n);
    clock_gettime(CLOCK_REALTIME, &b_time);
    insertionSort(bestInsertion,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    bestinsertion = get_execution_time(b_time,e_time);


    clock_gettime(CLOCK_REALTIME, &b_time);
    quickSort(array2,0,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    quicksort = get_execution_time(b_time,e_time);

    badArray(badQuicksort,n);
    clock_gettime(CLOCK_REALTIME, &b_time);
    quickSort(badQuicksort,0,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    badquick = get_execution_time(b_time,e_time);

    bestArray(bestQuick,n);
    clock_gettime(CLOCK_REALTIME, &b_time);
    quickSort(bestQuick,0,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    bestquick = get_execution_time(b_time,e_time);


    int auxiliar_array[n];
    initArray(auxiliar_array,n);
    int max = findMax(array3,n);
    //printf("max %d\n",max );
    clock_gettime(CLOCK_REALTIME, &b_time);
    //countingSort(array3,auxiliar_array,max,n);// -----> finire counting Sort
    clock_gettime(CLOCK_REALTIME, &e_time);
    counting = get_execution_time(b_time,e_time);


    clock_gettime(CLOCK_REALTIME, &b_time);
    radixSort(array4,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    radix = get_execution_time(b_time,e_time);


    clock_gettime(CLOCK_REALTIME, &b_time);
    //bucketSort(array5,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    bucket = get_execution_time(b_time,e_time);


    printf("%d\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t \n",
      n,insertion,badinsertion,bestinsertion,quicksort,badquick,bestquick,counting,radix,bucket);
    }
  return 0;
}
