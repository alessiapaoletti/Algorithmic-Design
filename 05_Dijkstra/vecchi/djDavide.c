// #include <stdio.h>
// #include <stdlib.h>
// #include "array_heap.h"
// #define INF 2147483647
//
//
//
//
// #include <stdio.h>
// #include <stdlib.h>
// 
// typedef struct Node {
//   int d;
//   int id;
//   int position;
//   struct Node *pred;
// } Node;
//
// typedef struct Array {
//   Node **A;
//   size_t size;
// } Array;
//
// int array_empty(Array *a) { return a->size == 0; }
//
// void freeArray(Array a) { free(a.A); }
//
// void array_swap(Node **a, Node **b) {
//   Node *temp = *a;
//   *a = *b;
//   *b = temp;
// }
//
// void array_remove(Array *a, int i) {
//   array_swap(&a->A[i], &a->A[a->size - 1]);
//   a->size--;
// }
//
// Node *extract_array_minimum(Array *a) {
//   int min = a->A[0]->d;
//   int min_index = 0;
//   for (int i = 1; i < a->size; i++) {
//     if (a->A[i]->d < min) {
//       min = a->A[i]->d;
//       min_index = i;
//     }
//   }
//
//   Node *n = a->A[min_index];
//   array_remove(a, min_index);
//   return n;
// }
//
// Array build_Array(Node *nodes, size_t n) {
//   Node **node_pointers = (Node **)malloc(sizeof(Node *) * n);
//   for (int i = 0; i < n; i++)
//     node_pointers[i] = &(nodes[i]);
//
//   Array a;
//   a.size = n;
//   a.A = node_pointers;
//
//   return a;
// }
//
// int array_findNode(Array *a, int node_id) {
//   for (int i = 0; i < a->size; i++)
//     if (node_id == a->A[i]->id)
//       return i;
//   return -1;
// }
//
// void show_Array(Array a) {
//   printf("\nArray: id:%d-d:%d", a.A[0]->id, a.A[0]->d);
//   for (int i = 1; i < a.size; i++)
//     printf(", id:%d-d:%d", a.A[i]->id, a.A[i]->d);
//   printf("\n");
// }
//
//
// typedef struct Graph
// {
//     Node* v; // list of nodes
//     int* weights_m; // adjacency matrix
//     int size; // n of nodes
// } Graph;
//
//
// void show_graph(Graph* g)
// {
//     int size = g->size;
//     printf("\nsize: %d\nweights:\n", g->size);
//
//     for(int i=0; i<size; i++)
//     {
//         for(int j=0; j<size; j++)
//         {
//             if(g->weights_m[size*i+j]==INF)
//                 printf("// ");
//             else
//                 printf("%2d ", g->weights_m[size*i+j]);
//         }
//         printf("\n");
//     }
//
//     for(int i=0; i<size; i++)
//     {
//         Node x = g->v[i];
//
//         printf("\n node %d, dist=%d", x.id, x.d);
//         if((x.pred)!=NULL)
//             printf(", pred=%d", x.pred->id);
//         else
//             printf(", /");
//
//     }
//
//     printf("\n");
// }
//
//
// // it returns the weight of the edge connecting the two given nodes
// int weight(Graph* g, Node* from, Node* to)
// {
//     return g->weights_m[from->id*g->size + to->id];
// }
//
//
// // returns a node from a graph given its id
// Node* getNode(Graph* g, int id)
// {
//     Node* v = g->v;
//     for(int i=0; i<g->size; i++)
//         if(v[i].id == id) return &v[i];
//     return NULL;
// }
//
//
// // returns the number of nodes adjacent to a given node
// int adjacents_len(Graph* g, Node* u)
// {
//     int n = 0;
//     for(int i=0; i<g->size; i++)
//     {
//         if((g->v)[i].id == u->id) continue;
//         n+=(weight(g,u,&(g->v)[i]))< INF;
//     }
//
//     return n;
// }
//
//
// // returns nodes adjacent to a given node
// Node** adjacents(Graph* g, Node* u, int n)
// {
//     Node** adj = (Node**) malloc(sizeof(Node*)*n);
//     int a = 0;
//     for(int i=0; i<g->size; i++)
//     {
//         int w = weight(g,u,&(g->v)[i]);
//         if(w<INF && (g->v)[i].id != u->id)
//                 adj[a++] = &(g->v)[i];
//     }
//
//     return adj;
// }
//
//
// // initializes the nodes of the graph for a Dijkstra search
// void initialize(Graph* g)
// {
//     int n = g->size;
//     for(int i=0; i<n; i++)
//     {
//         (g->v[i]).id = i;
//         (g->v[i]).d = INF;
//         (g->v[i]).pred = NULL;
//     }
// }
//
//
// void relax(Heap* q, Node* u, Node* v, int w)
// {
//     if(u->d + w < v->d)
//     {
//         update_distance(q, v, u->d + w);
//         v->pred = u;
//     }
// }
//
//
// void relax_array(Array* q, Node* u, Node* v, int w)
// {
//     if(u->d + w < v->d)
//     {
//         v->d = u->d + w; // the update is simpler in the array implementation
//         v->pred = u;
//     }
// }
//
//
// void Dijkstra_heap(Graph* g, int start_id)
// {
//     initialize(g);
//     Node* s = getNode(g, start_id);
//     s -> d = 0;
//
//     Heap Q = build_heap(g->v,  g->size, less);
//     Heap* q = &Q;
//
//     while(!empty(q))
//     {
//         Node* u = extract_minimum(q);
// 	int n =  adjacents_len(g, u);
//         Node** u_adj = adjacents(g, u, n);
//
//         for(int i=0; i<n; i++)
//             relax(q, u, u_adj[i], weight(g, u, u_adj[i]));
//         free(u_adj);
//     }
//     freeHeap(Q);
// }
//
//
// void Dijkstra_array(Graph* g, int start_id)
// {
//     initialize(g);
//     Node* s = getNode(g, start_id);
//     s -> d = 0;
//
//     Array Q = build_Array(g->v,  g->size);
//     Array* q = &Q;
//
//     while(!array_empty(q))
//     {
//         Node* u = extract_array_minimum(q);
// 	int n =  adjacents_len(g, u);
//         Node** u_adj = adjacents(g, u, n);
//
//         for(int i=0; i<n; i++)
//                 relax_array(q, u, u_adj[i], weight(g, u, u_adj[i]));
//
//         free(u_adj);
//
//     }
//     freeArray(Q);
// }
//
//
//
// #include <stdio.h>
// #include <stdlib.h>
// #include<time.h>
// #include "Dijkstra.h"
//
// int main()
// {
//     int size = 5;
//     int* adj_matrix = (int*) malloc(sizeof(int)*size*size);
//
//     for(int i=0; i<size*size; i++)
//         adj_matrix[i]=INF;
//
//     adj_matrix[size*0 + 1] = 5; adj_matrix[size*0 + 4] = 10;
//     adj_matrix[size*1 + 4] = 3; adj_matrix[size*1 + 3] = 9; adj_matrix[size*1 + 2] = 2;
//     adj_matrix[size*2 + 0] = 7; adj_matrix[size*2 + 3] = 6;
//     adj_matrix[size*3 + 2] = 4;
//     adj_matrix[size*4 + 1] = 2; adj_matrix[size*4 + 3] = 1;
//
//     Graph g;
//     g.size=size;
//     g.weights_m = adj_matrix;
//     g.v = (Node*) malloc(sizeof(Node)*size);
//
//     printf("starting graph\n");
//     show_graph(&g);
//
//     printf("\n\n\n");
//
//     printf("array solution\n");
//     Dijkstra_array(&g, 0);
//     show_graph(&g);
//
//     printf("\n\n\n");
//
//     printf("heap solution\n");
//
//     Dijkstra_heap(&g, 0);
//     show_graph(&g);
//
//     free(adj_matrix);
//     free(g.v);
//
//     return 0;
// }
