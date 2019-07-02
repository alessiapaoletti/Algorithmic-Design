#include <stdlib.h>
#include <math.h>
#include "../include/utility.h"
#include "../include/sorting.h"

int selectPivot(int *A, int start, int end){
  // printf("dentro stampo array A \n");
  // printArray(A,n);
  //n = n+1;
  //int *B = (int*)malloc(sizeof(int)*n);
  //for (size_t i = 0; i < n; i++) B[i] = A[i];
  //B = copyArray(A,n); //array used to perform the selectPivot algorithm
  // printf("dentro stampo array B \n");
  // printArray(B,n);
  // for (int i = start; i <= end; i++) {
  //   printf("B[%d] = %d\n",i,B[i] );
  // }
  int N = 5; // number of the medians
  int pivot;
  int numElementChunck = (end-start+1)/5;
  int *B;
  int median[N]; //vector of the medians
  //printf("numElementChunck %d\n",numElementChunck );
  if (numElementChunck < 1 ) return start; //return the only element in the array
  else B = (int*) malloc (sizeof(int)*(end-start+1));
  copyPartialArray(B,A, start, (end-start+1));

  //int rest = n % N; //to know the size of the last chunck

//  to deal with the rest
/*
  if (rest!=0){ //manage the last chuck considering the rest
    int start = (N-1)*numElementChunck;
    int end = start+rest;
    insertionSortbegin(B,start,rest);
    int idx = (start+end)/2;
    median[N-1] = B[idx];
  }
  else N = N+1; //così il ciclo for sotto lo facccio una volta in più (ossia anche per l'ultimo chunck)

  //if the rest = 0 does the "for" cycle for N chuncks, otherwise for N-1 chuncks (since I have already done it for the last one)
  for (int i = 0; i < N-1; i++) {
    int start = i*numElementChunck;
    int end = start + numElementChunck;
    insertionSortbegin(B,start,numElementChunck);
    int idx = (start+end)/2;
    median[i] = B[idx];
  }
*/

  for (int i = 0; i < N; i++) {
    insertionSortbegin(B, i*numElementChunck, numElementChunck);
    median[i] = B[(i*numElementChunck)+numElementChunck/2];
  }

  //Bisogna farlo ?? sort the medians ?
  insertionSortbegin(median,0,5); //order the array of the medians
  //printf("array mediane dentro select Pivot: \n");
  //printArray(median,5);

  //find the position of the median of the medians' array in the original array
  for (int i = start; i <= end; i++) {
    if (A[i] == median[N/2]){
     pivot = i;
     break;
   }
  }
  //printf("the pivot is %d, position %d \n",A[pivot], pivot );
  free(B);
  return pivot; //return
}

int partitionSelect(int* A, int left, int right){
  int pivotIdx = selectPivot(A, left, right);
  swap(&A[left], &A[pivotIdx]); //swap the first element with the partition element

	pivotIdx = left; //the partition index becomes the index of the first element
	left = left+1;

	while (left <= right) {
    if (A[left]>A[pivotIdx]) { //if the number is greater than the pivot
			swap(&A[left],&A[right]); //move it to the right
			right = right-1;//decrease right
		}
    else left=left+1; //otherwise increase left
  }
  swap(&A[right],&A[pivotIdx]);
  return right;
}

int myselect(int *A, int i, int l, int r, const int n){ //i is the index of the elements for what I want to find the position in the sorted array
  int k = partitionSelect(A,l,r);
  //int k = selectPivot(A,l,r,n);
  // int k = partitionPivot(A,l,r,j);
  //printf("index =%d\t k=%d\n",i,k );
  if (i==k) return k;
  else if (i<k) return myselect(A,i,l,k-1,n);
  else return myselect(A,i,k+1,r,n);
}
