#ifndef __UTILITY__
#define __UTILITY__

#include <string.h>
#include <stdlib.h>

int* copyArray(int const * src, size_t len);
double get_execution_time(const struct timespec b_time, const struct timespec e_time);

#endif
