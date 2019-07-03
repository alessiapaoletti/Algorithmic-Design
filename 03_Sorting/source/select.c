#include <stdlib.h>
#include <math.h>
#include "../include/utility.h"
#include "../include/sorting.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int selectPivot(int* A, int l, int r)
{
  //if I have only one chunck -> return its median
  if(r-l<5){
    insertionSortbegin(A,l,r);
		return (l+r)/2; //return the index of the median
	}

	int n_chunck = ((r-l)/5)+1;

	for(int i=0;i<n_chunck;i++) {
    int startIndex = 5 * i + l;
    //for the endIndex I have to be aware of the last chunck (can be not full)
    int endIndex;
    if ((startIndex + 5) < r) endIndex = startIndex + 5;
    else endIndex = r;
    insertionSortbegin(A, startIndex, endIndex);
  }

	for(int i=0;i<n_chunck;i++){
    //put the medians at the begin of each chunck
    int idx2 = MIN(5*i + l + 2, r-1);
    swap(&A[l+i], &A[idx2]);
  }

  //recursion until I have one chunck
	int res = selectPivot(A, l, l+n_chunck);
	return res;
}


/* Partition given the pivot and able to deal with the duplicates,
the duplicates are randomly assigned on the left or on the right */
int partitionNew(int* A, int begin, int end, int pivot)
{
  swap(&A[begin], &A[pivot]); //pivot in the first position
  pivot = begin; // new position of the pivot in the array

  int right = 0; //auxiliar variable to deal with duplicates

  while (begin <= end) {
    if (A[begin] > A[pivot]) { //if element greater than pivot swap to the end
      swap(&A[begin], &A[end]);
      end--; //reduce end index
    }

    else if (A[begin] == A[pivot]) {
      if (right) {
        swap(&A[begin], &A[end]);
        end--;
        right = 0;
      } else {
        begin++;
        right = 1;
      }
    }

    else begin++; //the element is in the right place
  }

  swap(&A[pivot], &A[end]); //now end has the index of the middle element
  return end;
}


int myselect(int* A, int i, int begin, int end)
{
  int j = selectPivot(A, begin, end);
  int k = partitionNew(A, begin, end, j);
  if (i == k+1) return A[k];
  if (i < k+1) return myselect(A, i, begin, k - 1);
  return myselect(A, i, k + 1, end);
}
