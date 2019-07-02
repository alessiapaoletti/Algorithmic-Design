#ifndef __SELECT__
#define __SELECT__

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
void insertionSortbegin(int *A, int begin, int end);
int selectPivot(int *A, int start, int end);
int myselect(int *A, int i, int l, int r, const int n);

#endif //__SELECT__
