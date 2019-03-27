#ifndef __UTILITY__

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int *A, int n);
void badArray(int *A, int n);
void bestArray(int *A, int n);
double get_execution_time(const struct timespec b_time, const struct timespec e_time);
void swap(int *a, int *b);
int findMax(int * A, int n);
void initArray(int *A, int n); 

#endif // __UTILITY__
