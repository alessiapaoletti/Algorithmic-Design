struct heap {
  int * array;
  int n;
  enum {MIN,MAX} type;
};

typedef struct heap heap;

//Given an array of element create an Heap
heap createHeap(int * array, int array_lenght, /*enum type*/) {
  heap A;
  A.n = array_lenght;
  //A.type = type;
  int x =
  for (int i = A.n/2; i <1; i-- ){
    Heapify(A,i);
  }
  return A;
}

void Heapify(heap A, int i) {
  // if (A.type == 0) minHeapify(A,i);
  // else if (A.type == 1) maxHeapify(A,i);
  // else printf("Problema con il type \n");



}

void findMinimum(A) {
  return A.array[0];
}
void extractMin()
void decreaseKey()
void insertValue()

int getLeftChild(heap A, int i) {
  if (A.array[2*i]) return A.array[2*i];
  else return NULL;
}

int getRightChild(heap A, int i) {
  if (return A.array[2*i+1]) return A.array[2*i+1];
  else return NULL;
}

int getParent(heap A, int i) {
  return A.array[i/2];
}

bool is_root(A,i){
  if (A.array[i] == A.array[0]) return TRUE;
  return FALSE;
}

bool is_valid_node(A,i){
  if i>=A.n return FALSE;
  return TRUE;
}

int get_root(A){
  return A.array[0]; 
}




int main() {
  int array[10];
  array[0] = 1;
  heap prova;
  prova.array = array;
  prova.n = 5;
  prova.type = MAX;

  //perchè warning quando stampo ??
  // printf("prova.n %d\n", prova.n );
  // printf("prova.array[0] %d\n", prova.array[0] );
  // printf("prova.type %d\n", prova.type);

  return 0;
}
