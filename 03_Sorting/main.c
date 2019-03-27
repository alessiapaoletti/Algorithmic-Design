#include <stdio.h>
#include <stdlib.h>
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

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}

void insertionSort(int *A, int n) {
  int i,j,key;
  for (j=1; j<n; j++){
    key = A[j];
    i = j-1;
    while (i>=0 && A[i]>key){
      A[i+1] = A[i];
      i = i-1;
    }
    A [i+1] = key;
  }
}

void swap(int *a, int *b)
{
   int t;
   t  = *b;
   *b = *a;
   *a = t;
}

int partition(int *A, int l, int r){
  int pivot,i,j;
  pivot = A[r]; //choose the last element as the pivot
  i = l-1;

  for (j = l; j<= r-1; j++){
    if(A[j] <= pivot) {
      i = i+1;
      swap(&A[i],&A[j]);
    }
  }
    swap(&A[i+1],&A[r]);
    return i+1;
}

void quickSort(int *A, int l, int r){
  r = r-1; // to make the call quickSort(A,0,n) insthead of quickSort(A,0,n-1)
  int p;
  while (l<r){
    p = partition(A,l,r);
    quickSort(A,l,p-1);
    l = p+1;
    l++;
  }
}

int findMax(int * A, int n ) {
  int max = A[0];
  for (size_t i = 1; i < n; i++) {
    if (A[i]>max)
      max = A[i];
  }
  return max;
}

void countingSort(int *A, int *B, int k,int n){
  int C[k];
  for (size_t i = 0; i < k; i++) {
    C[i]=0;
  }
  printArray(C,k);
  printf("\n");
  for (size_t j = 0; j < n; j++) {
    C[A[j]] = C[A[j]]+1;
  }
  printArray(C,k);
  printf("\n");

  for (size_t i = 1; i < k; i++) {
    C[i] = C[i] + C[i-1];
  }
  printArray(C,k);
  printf("\n");

  for (size_t j = n-1; j > 0 ; j--) {
    printf("sono dentro for %d %d  \n",  A[j], C[A[j]]-1);
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
  printArray(B,n);

}


void radixSort(int * array, int size){
  // Base 10 is used
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findMax(array, size);

  // Loop until we reach the largest significant digit
  while (largestNum / significantDigit > 0){

    //printf("\tSorting: %d's place ", significantDigit);
    //printArray(array, size);

    int bucket[10] = { 0 };

    // Counts the number of "keys" or digits that will go into each bucket
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;

    /**
     * Add the count of the previous buckets,
     * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
     **/
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    // Use the bucket to fill a "semiSorted" array
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];


    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];

    // Move to next significant digit
    significantDigit *= 10;

    //printf("\n\tBucket: ");
    //printArray(bucket, 10);
  }
}

void bucketSort(int *A, int n)
{
    int aux[n];
    for (size_t i = 0; i < n; i++)
        aux[i] = 0;

    for (size_t i = 0; i < n; i++)
        (aux[A[i]])++;

    for (size_t i = 0, j = 0; i < n; i++)
        for(; aux[i] > 0; (aux[i])--)
            A[j++] = i;
}




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
    for (size_t i = 0; i < n; i++) {
      auxiliar_array[i] = 0;
    }
    //printArray(array3,n);
    int max = findMax(array3,n);
    //printf("max %d\n",max );
    clock_gettime(CLOCK_REALTIME, &b_time);
    //countingSort(array3,auxiliar_array,max,n);// -----> finire counting Sort
    clock_gettime(CLOCK_REALTIME, &e_time);
    //printArray(array1,n);
    counting = get_execution_time(b_time,e_time);


    //printArray(array2,n);
    clock_gettime(CLOCK_REALTIME, &b_time);
    radixSort(array4,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    //printArray(array2,n);
    radix = get_execution_time(b_time,e_time);


    clock_gettime(CLOCK_REALTIME, &b_time);
    //bucketSort(array5,n);
    clock_gettime(CLOCK_REALTIME, &e_time);
    bucket = get_execution_time(b_time,e_time);


    printf("%d\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t \n",n,insertion,badinsertion,bestinsertion,quicksort,badquick,bestquick,counting,radix,bucket);
    }













  return 0;
}
