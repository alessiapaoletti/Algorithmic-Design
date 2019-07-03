#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/utility.h"
#include "../include/select.h"
#include "../include/sorting.h"

int main() {

  struct timespec b_time, e_time;
  int n = 12;
  int* A = (int*)malloc(sizeof(int) * n);
  for(int j = 0; j < n ; j++)
   A[j] = n-j+10;

  for (int j = 0; j < n; j++) {
    int index = j+1;
    clock_gettime(CLOCK_REALTIME, &b_time);
    int selected = myselect(A,index , 0, n - 1);
    clock_gettime(CLOCK_REALTIME, &e_time);
    printf("%dth element=%d \t time =%lf\n\n", index, selected, get_execution_time(b_time, e_time));
  }

  insertionSort(A, n);
  printArray(A,n);
  free(A);

  return 0;
}
