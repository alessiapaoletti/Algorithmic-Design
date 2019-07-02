#include <time.h>
#include <string.h>
#include <stdlib.h>

int* copyArray(int const * src, size_t len){
   int * p = malloc(len * sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}

double get_execution_time(const struct timespec b_time, const struct timespec e_time){
  return (e_time.tv_sec-b_time.tv_sec) +
                   (e_time.tv_nsec-b_time.tv_nsec)/1E9;
}
