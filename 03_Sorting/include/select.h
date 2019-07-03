#ifndef __SELECT__
#define __SELECT__

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int myselect(int* A, int i, int left, int right);
int partitionNew(int* array, int begin, int end, int pivot);
int selectPivot(int* array, int begin, int end);



#endif //__SELECT__
