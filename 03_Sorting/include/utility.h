#ifndef __UTILITY__
#define __UTILITY__

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct Node {
  double value;
  struct Node * next;
};
typedef struct Node Node;

void printArray(int *A, int n);
void increasingArray(int *A, int n);
void descreasingArray(int *A, int n);
double get_execution_time(const struct timespec b_time, const struct timespec e_time);
void swap(int *a, int *b);
int findMaxArray(int * A, int n);
void initArray(int *A, int n);
int *copyArray(int const * src, size_t len);
void copyPartialArray(int* A1 , const int*A2 , const int start, const int n);
void printBucket(Node* const head);
Node* append(Node *head, const double value);
double getValueList(Node * head, int j);
void swapNode(Node *a, Node *b);
size_t listSize(Node* const head);

#endif // __UTILITY__
