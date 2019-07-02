#include "../include/heap.h"

/***** Array struct and methods *****/
struct Array {
  Node **A; //array di puntatotori a puntatotori di Nodes
  int size;
};
typedef struct Array Array;

Array buildArray(Node *nodes, int n){
  Node ** Nodes_pointers = (Node**) malloc (sizeof(Node*)*n);
  for (int i = 0; i < n; i++) {
    Nodes_pointers[i] = &(nodes[i]); //devo puntare ai nodi inizializzati
  }

  Array Q_Array;
  Q_Array.A = Nodes_pointers;
  Q_Array.size = n;
  return Q_Array;
}

int arrayEmpty(Array *A) {return (A->size == 0);}

void arraySwap(Node **a, Node **b) { //to swap 2 nodes
  Node *temp = *a;
  *a = *b;
  *b = temp;
}

void relaxArray(Node* u, Node* v, int w){
    if(u->distance + w < v->distance){
        v->distance = u->distance + w; // the update is simpler in the array implementation
        v->prev_node = u;
    }
}

void arrayRemove(Array *q, int i) {
  //swap the element in the index i with the last one
  //so we can simply decrease the size and "delete" (lost the connection)
  //with the last element
  arraySwap(&q->A[i], &q->A[q->size - 1]);
  q->size--; //decrease the size
}

Node* extractMinArray(Array *q) {

  //set as min the first element
  int min_distance = q->A[0]->distance;
  int min_index = 0;

  //find the minimum in the array
  for (int i = 1; i < q->size; i++) {
    if (q->A[i]->distance < min_distance) {
      //update the min value and index
      min_distance = q->A[i]->id;
      min_index = i;
    }
  }

  //Once we have found the min we have to extract it
  Node *u = q->A[min_index];

  //and remove it from the array
  arrayRemove(q, min_index);
  return u;
}

/***** End Array methods *****/

struct Graph{
  Node *nodes; //list of nodes
  int **adj_list;  //adjacency matrix
  int num_vertex; //number of vertex
};
typedef struct Graph Graph;

void relax(Heap* q, Node* u, Node* v, int w)
{
    if(u->distance + w < v->distance)
    {
        updateDistance(q, v, u->distance + w);
        v->prev_node = u;
    }
}

void initializeGraph(Graph *g){
  for (int i = 0; i < g->num_vertex; i++) {
    g->nodes[i].id = i;
    g->nodes[i].distance = INT_MAX;
    g->nodes[i].prev_node = NULL;
  }
}

Node* getNode(Graph *g, int idNode){
  for (int i = 0; i < g->num_vertex; i++) {
    if (g->nodes[i].id == idNode) return &(g->nodes[i]);
  }
  return NULL;
}

int weight(Graph* g, Node* from, Node* to){
  return g->adj_list[from->id][to->id];
}

int lengthAdj(Graph *g, Node *u){
  int n = 0;
  for(int i=0; i<g->num_vertex; i++){
      if((g->nodes)[i].id == u->id) continue;
      n+=(weight(g,u,&(g->nodes)[i]))< INT_MAX;
  }
  return n;
}

Node** adjacents(Graph* g, Node* u, int n)
{
    Node** adj = (Node**) malloc(sizeof(Node*)*n);
    int a = 0;
    for(int i=0; i<g->num_vertex; i++)
    {
        int w = weight(g,u,&(g->nodes)[i]);
        if(w<INT_MAX && (g->nodes)[i].id != u->id)
                adj[a++] = &(g->nodes)[i];
    }

    return adj;
}


/********* Dijkstra Algorithms *********/

void dijkstraArray(Graph *g, int start_node){
  initializeGraph(g);
  Node *s = getNode(g,start_node);
  s->distance = 0;

  Array Q = buildArray(g->nodes, g->num_vertex); //create the queue as an array
  Array *Q_pointer = &Q; //create a pointer to the array (so we can use it as the normal array)

  while(!arrayEmpty(Q_pointer)){
    //extract the minimum
    Node* u = extractMinArray(Q_pointer);
    int n =  lengthAdj(g, u);
    Node** u_adj = adjacents(g, u, n);

    for(int i=0; i<n; i++)
      relaxArray(u, u_adj[i], weight(g, u, u_adj[i]));
    //free(u_adj);
  }
  //free(Q_pointer);
}


void dijkstraHeap(Graph *g, int start_node){
  initializeGraph(g);
  Node *s = getNode(g,start_node);
  s->distance = 0;

  Heap Q = buildMinHeap(g->nodes, g->num_vertex); //create the queue as a MinHeap
  Heap *Q_pointer = &Q; //create a Q_pointer

  while(!emptyHeap(Q_pointer)){
    Node* u = extractMin(Q_pointer);

    int n =  lengthAdj(g, u);
    Node** u_adj = adjacents(g, u, n);

    for(int i=0; i<n; i++)
      relax(Q_pointer, u, u_adj[i], weight(g, u, u_adj[i]));
    // //free(u_adj);
  }
  //free(Q_pointer);
}


void printGraph(Graph* g)
{
    int size = g->num_vertex;
    for(int i=0; i<size; i++)
    {
        Node x = g->nodes[i];
        printf("\nnode %d, dist=%d", x.id, x.distance);
        if((x.prev_node)!=NULL)
            printf(", pred=%d", x.prev_node->id);
        else
            printf(", /");

    }
    printf("\n");
}

void printMatrix(int** matrix, int n_row, int n_col){
  for (int i = 0; i < n_row; i++) {
    for (int j = 0; j < n_col; j++) {
      if (matrix[i][j] == INT_MAX) printf("INF\t");
      else printf("%d\t",matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {

  int size = 6;
  int** adj_matrix = (int**) malloc(sizeof(int*)*size);
  for (int i = 0; i < size; i++)
    adj_matrix[i] = (int*)malloc(sizeof(int)*size);

  for(int i=0; i<size; i++){
    for (int j = 0; j < size; j++){
      adj_matrix[i][j]=INT_MAX;
    }
  }

  adj_matrix[0][1] = 1;
  adj_matrix[0][2] = 5;
  adj_matrix[1][5] = 15;
  adj_matrix[2][3] = 2;
  adj_matrix[3][4] = 1;
  adj_matrix[4][5] = 3;

  // adj_matrix[0][1] = 1;
  // adj_matrix[0][2] = 5;
  // adj_matrix[1][2] = 2;
  // adj_matrix[1][3] = 3;
  // adj_matrix[1][4] = 4;
  // adj_matrix[2][4] = 3;
  // adj_matrix[2][5] = 3;
  // adj_matrix[3][2] = 4;
  // adj_matrix[3][6] = 5;
  // adj_matrix[5][4] = 6;
  // adj_matrix[5][7] = 10;
  // adj_matrix[6][7] = 5;


  //the adj is simmetric, I need to do that
  // adj_matrix[1][0] = 1;
  // adj_matrix[2][0] = 5;
  // adj_matrix[2][1] = 2;
  // adj_matrix[3][1] = 3;
  // adj_matrix[4][1] = 4;
  // adj_matrix[4][2] = 3;
  // adj_matrix[5][2] = 3;
  // adj_matrix[2][3] = 4;
  // adj_matrix[6][3] = 5;
  // adj_matrix[4][5] = 6;
  // adj_matrix[7][5] = 10;
  // adj_matrix[7][6] = 5;



  // adj_matrix[0][1] = 3;
  // adj_matrix[0][2] = 1;
  // adj_matrix[1][2] = 7;
  // adj_matrix[1][3] = 5;
  // adj_matrix[1][4] = 1;
  // adj_matrix[2][3] = 2;
  // adj_matrix[3][4] = 7;
  //
  // adj_matrix[1][0] = 3;
  // adj_matrix[2][0] = 1;
  // adj_matrix[2][1] = 7;
  // adj_matrix[3][1] = 5;
  // adj_matrix[4][1] = 1;
  // adj_matrix[3][2] = 2;
  // adj_matrix[4][3] = 7;



  Graph g;
  g.num_vertex=size;
  g.adj_list = adj_matrix;
  g.nodes = (Node*) malloc(sizeof(Node)*size);
  printf("**** Adj Matrix ****\n");
  printMatrix(adj_matrix,size,size);

  printf("\n\n**** Array solution ****\n");
  dijkstraArray(&g, 0);
  printGraph(&g);

  printf("\n**** Heap solution ****\n");
  dijkstraHeap(&g, 0);
  printGraph(&g);

	return 0;
}
