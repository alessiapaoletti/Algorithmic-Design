// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
//
//
//
//
// // Node of the adjacency list
// struct node {
//     int vertex;
//     int weight;
//     struct node * next;
// };
//
// // Each element of the priority queue (min heap)
// // is a pair of vertex and a value (its distance)
// struct vertex
// {
// 	int vertex;
//   int dist;
// };
//
// // struct heap {
// //   int *array;
// //   int size;
// //   enum {MIN,MAX} type;//0 min, 1 max
// // };
// //
// // typedef
//
// // Follows head insertion to give O(1) insertion
// struct node * addEdge(struct node * head, int vertex, int weight)
// {
//     struct node * newNode = (struct node *) calloc(1, sizeof(struct node));
//     newNode->vertex = vertex;
//     newNode->weight = weight;
//     newNode->next = head;
//
//     return newNode;
// }
//
// // Applies the heapify_ procedure - O(log N)
// void heapify_(struct vertex minHeap[], int size, int i, int pos[])
// {
// 	struct vertex temp;
//
//     while ((2 * i) <= size) {
//         if ((2 * i) + 1 > size) {
// 			if (minHeap[i].dist > minHeap[2 * i].dist) {
// 				pos[minHeap[i].vertex] = 2 * i;
// 				pos[minHeap[2 * i].vertex] = i;
//
//                 temp = minHeap[i];
//                 minHeap[i] = minHeap[2 * i];
//                 minHeap[2 * i] = temp;
//             }
//
//             break;
//         }
//
//         if (minHeap[i].dist > minHeap[2 * i].dist || minHeap[i].dist > minHeap[2 * i + 1].dist) {
//             if (minHeap[2 * i].dist <= minHeap[(2 * i) + 1].dist) {
//                 pos[minHeap[i].vertex] = 2 * i;
// 				pos[minHeap[2 * i].vertex] = i;
//
//                 temp = minHeap[2 * i];
//                 minHeap[2 * i] = minHeap[i];
//                 minHeap[i] = temp;
//
//                 i = 2 * i;
//             } else if (minHeap[2 * i].dist > minHeap[(2 * i) + 1].dist) {
//                 pos[minHeap[i].vertex] = 2 * i + 1;
// 				pos[minHeap[2 * i + 1].vertex] = i;
//
//                 temp = minHeap[(2 * i) + 1];
//                 minHeap[(2 * i) + 1] = minHeap[i];
//                 minHeap[i] = temp;
//
//                 i = (2 * i) + 1;
//             }
//         } else {
//             break;
//         }
//     }
// }
//
// // Build Heap Procedure - O(N)
// void build_Heap(struct vertex minHeap[], int size, int pos[])
// {
//     int i;
//
//     for (i = size / 2; i >= 1; --i) {
//         heapify_(minHeap, size, i, pos);
//     }
// }
//
// // Searches for a node in the Heap in O(1) time and decreases its value
// // Then calls heapify_() on it's parent to adjust heap -> totally takes O(log N) time
// void decrease_Key(struct vertex minHeap[], struct vertex newNode, int pos[])
// {
// 	minHeap[pos[newNode.vertex]].dist = newNode.dist;
//
// 	int i = pos[newNode.vertex];
// 	struct vertex temp;
//
//     while (i > 1) {
//         if (minHeap[i / 2].dist > minHeap[i].dist) {
//             pos[minHeap[i].vertex] = i / 2;
// 			pos[minHeap[i / 2].vertex] = i;
//
//             temp = minHeap[i / 2];
//             minHeap[i / 2] = minHeap[i];
//             minHeap[i] = temp;
//
//             i = i / 2;
//         } else {
//             break;
//         }
//     }
// }
//
// // Removes and Returns the topmost element - O (log N)
// struct vertex extract_Min(struct vertex minHeap[], int size, int pos[])
// {
// 	pos[minHeap[1].vertex] = size;
// 	pos[minHeap[size].vertex] = 1;
//
// 	struct vertex min = minHeap[1];
//
// 	minHeap[1] = minHeap[size];
// 	--size;
// 	heapify_(minHeap, size, 1, pos);
//
// 	return min;
// }
//
// // Dijkstra's Algorithm function
// void dijkstra(struct node * adjacencyList[], int num_vertices, int startVertex, int* distances, int* parent)
// {
//     struct vertex minVertex;
//     struct vertex priorityQueue[num_vertices]; //queue of vertices
//     int pos[num_vertices]; //array of integer
//
//     /* Initialization */
//     for (int i = 0; i < num_vertices; ++i) {
//         distances[i] = INT_MAX;
//         parent[i] = -1;
//         priorityQueue[i].dist = INT_MAX;
//         priorityQueue[i].vertex = i;
// 		    pos[i] = priorityQueue[i].vertex;
//     }
//     /* Source vertex */
//     distances[startVertex] = 0;
//     priorityQueue[startVertex].dist = 0;
//
//
//     build_Heap(priorityQueue, num_vertices, pos);
//
//     for (int i = 0; i < num_vertices; ++i) {     // Untill there are vertices to be processed
// 		minVertex = extract_Min(priorityQueue, num_vertices, pos);   // Greedily process the nearest vertex
//
// 		struct node * trav = adjacencyList[minVertex.vertex];    // Checking all the vertices adjacent to 'min'
//
//         while (trav != NULL) {
//         	int u = minVertex.vertex;
//         	int v = trav->vertex;
//         	int w = trav->weight;
//
//             if (distances[u] != INT_MAX && distances[v] > distances[u] + w) {
//                 // We have discovered a new shortest route, make the neccesary adjustments in data
//                 distances[v] = distances[u] + w;
//                 parent[v] = u;
//
//                 // Making changes to the priority queue
//                 struct vertex changedVertex;
//
//                 changedVertex.vertex = v;
//                 changedVertex.dist = distances[v];	// new distance
//                 decrease_Key(priorityQueue, changedVertex, pos);
//             }
//
//             trav = trav->next;
//         }
//     }
// }
//
// // Recursively looks at a vertex's parent to print the path
// void printPath(int parent[], int vertex, int startVertex)
// {
//     if (vertex == startVertex) {	// reached the source vertex
//         printf("%d ", startVertex);
//         return;
//     } else if (parent[vertex] == 0) {	// current vertex has no parent
//     	printf("%d ", vertex);
//     	return;
// 	} else {	// go for the current vertex's parent
//         printPath(parent, parent[vertex], startVertex);
//         printf("%d ", vertex);
//     }
// }
//
// int main()
// {
//     int num_vertices = 6;
//     int num_edges = 7;
//
//     struct node * adjacencyList[num_vertices];	// to use the array as 1-indexed for simplicity
//     int distances[num_vertices];
//     int parent[num_vertices];
//
//     /*Initialization of the array */
//     for (int i = 0; i <num_vertices; ++i) {	// Must initialize your array
//         adjacencyList[i] = NULL;
//     }
//
//     adjacencyList[0]=addEdge(adjacencyList[0],1,4);
//     adjacencyList[0]=addEdge(adjacencyList[0],2,3);
//     adjacencyList[1]=addEdge(adjacencyList[1],2,1);
//     adjacencyList[1]= addEdge(adjacencyList[1],3,2);
//     adjacencyList[2]=addEdge(adjacencyList[2],3,4);
//     adjacencyList[3]=addEdge(adjacencyList[3],4,2);
//     adjacencyList[4]=addEdge(adjacencyList[4],5,6);
//
//     int startVertex = 0;
//
//     dijkstra(adjacencyList, num_vertices, startVertex, distances, parent);
// 	  printf("Shortest distances -\n");
//
//     for (int i = 0; i < num_vertices; ++i) {
//     	printf("Vertex %d, Distance = %d, Parent = %d, ", i, distances[i], parent[i]);
//     	printf("Path = ");
//     	printPath(parent, i, startVertex);
//     	printf("\n");
// 	}
//
//     return 0;
// }
