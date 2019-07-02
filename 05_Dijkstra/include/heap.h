#ifndef __HEAPARR__
#define __HEAPARR__

#include <stdlib.h>
#include<stdio.h>
#include <limits.h>

struct Node{
  int id; //id of the Vertex
  int distance; //distance from the source
  int position; //needed for the implementation with the Heap
  struct Node * prev_node; //predecessor node (parent)
};
typedef struct Node Node;

struct Heap {
  Node **array;
  int size;
  //enum {MIN,MAX} type;//0 min, 1 max --> in this case we need only a minheap
};
typedef struct Heap Heap;

void printHeap(Heap *A);
int is_valid_node(Heap* H, int i);
void swapHeap(Node** a, Node** b);
void minHeapify(Heap *H, size_t i);
Heap buildMinHeap(Node *sourceArray, int n);
Node* extractMin(Heap *H);
int parent(int i);
size_t left (size_t i);
size_t right (size_t i);
int is_valid_node(Heap* H, int i);
Node* findMin(Heap *H);
int isRoot(int i);
void decreaseKey(Heap *H, int i, int value);
int emptyHeap(Heap* H);
void updateDistance(Heap* h, Node* v, int w);

#endif //__HEAPARR__
