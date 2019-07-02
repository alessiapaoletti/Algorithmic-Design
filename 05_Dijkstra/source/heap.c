#include "../include/heap.h"

Node* findMin(Heap *H){
  return H->array[0];
}

size_t right(size_t i){
    return 2*i + 2;
}

size_t left(size_t i){
    return 2*i + 1;
}

int parent(int i){
    return (i-1)/2;
}

void printHeap(Heap *H){
  if (H->size == 0) {
    printf("The heap is empty\n");
    return;
  }

  for (int i = 0; i < H->size; i++) {
    if (H->array[i]->distance == INT_MAX) printf("INF\t");
    else printf("%d\t",H->array[i]->distance);
  }
  printf("\nThe size of the heap is: %d\n",H->size);
}

int isRoot(int i){
  return i == 0;
}

int is_valid_node(Heap* H, int i){
  return i <= (H->size -1);
}

void swapHeap(Node** a, Node** b){

    int t_pos = (**a).position;
    (**a).position = (**b).position;
    (**b).position = t_pos;

    Node* temp = *a;
    *a = *b;
    *b = temp;
}

int emptyHeap(Heap* H) {return H->size==0; }

void decreaseKey(Heap *H, int i, int value){
  // if (H->array[i]->distance < value) printf("The value is not smaller.\n");
  // else{
    H->array[i]->distance = value;
    while (!isRoot(i) && H->array[i]<=H->array[parent(i)]){
      swapHeap(&(H->array[i]),&(H->array[parent(i)]));
      i = parent(i);
    //}
  }
}

void updateDistance(Heap* H, Node* v, int w)
{
    int pos = v->position;
    decreaseKey(H, pos, w);
}

// for MinHeap
void minHeapify(Heap *H, size_t m){
  size_t k = -1;
  while (k!=m){
    k = m;
    int children[2] = {left(k),right(k)}; //indices of right and left
    for (int j = 0; j < 2; j++)
      if (is_valid_node(H, children[j]) && ((H->array[children[j]]->distance) <= (H->array[m]->distance)))
        m = children[j];
    if (k!=m)
      swapHeap(&(H->array[k]),&(H->array[m]));
  }
}

Heap buildMinHeap(Node *sourceArray, int n){
   Node** node_pointers = (Node**) malloc(sizeof(Node*)*n);
   for(int i=0; i<n; i++)
   {
       sourceArray[i].position = i;
       node_pointers[i]=&(sourceArray[i]);
   }

   Heap H;
   H.size = n;
   H.array = node_pointers;

    int lastParentIdx = parent(H.size-1);
    for (int i =  lastParentIdx; i >= 0; i--) {
      minHeapify(&H,i);
    }
    return H;
}

Node* extractMin(Heap *H){
  Node* min = H->array[0];
  H->array[0] = H->array[H->size-1];
  H->size--;
  minHeapify(H,0);
  return min;
}
