// #include<stdio.h>
// #include<limits.h>
// #include <stdbool.h>
// #include <limits.h>
//
// #include "heap.h"
// #define FALSE 0
// #define TRUE 1
//
// #define N_VERT 8 //number of vertices in the graph
//
// //find the N_VERT with minimum distance which is not included in visited
// int minDist(int dist[], bool visited[])
// {
// 	int min=INT_MAX;
//   int index;
// 	for(int v=0;v<N_VERT;v++)
// 	{
// 		if(visited[v]==FALSE && dist[v]<=min)
// 		{
// 			min=dist[v];
// 			index=v;
// 		}
// 	}
// 	return index;
// }
//
//
// void dijkstra_array(int ,node src){
// 	//int dist[N_VERT]; //distance vector
// 	bool visited[N_VERT]; //visited vector, TRUE if visited
//
//   /* Initialization */
// 	for(size_t i=0; i<N_VERT; i++){
// 		//dist[i]=INT_MAX;
// 		visited[i]=FALSE;
// 	}
// 	//dist[src]=0;
// 	g->src->distance = 0;
//
// 	for(size_t i=0; i<N_VERT; i++)
// 	{
//     //u is any N_VERT that is not yet included in visited and has minimum distance
//     int u=minDist(dist,visited);
//     //If the N_VERT with minimum distance found include it to visited
// 		visited[u]=TRUE;
// 		for(int v=0; v<N_VERT; v++)
// 		/*Update dist[v] if not in visited and their is a path from src to v through u that has distance minimum than current value of dist[v]*/
// 		{
//       /*Relax */
// 			if(!visited[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
// 			dist[v]=dist[u]+graph[u][v];
// 		}
// 	}
//
//   /*Print the output */
// 	printf("N_VERT\t\tDistance from source \n");
// 	for(size_t i=0;i<N_VERT;i++)
//     printf("%ld\t\t %d\n",i, dist[i]);
// }
//
// // void dijkstra_heap(int graph[N_VERT][N_VERT],int src){
// // 	int dist[N_VERT]; //distance vector
// // 	bool visited[N_VERT]; //visited vector, TRUE if visited
// //
// //   /* Initialization */
// //
// // 	for(size_t i=0; i<N_VERT; i++){
// // 		dist[i]=INT_MAX;
// // 		visited[i]=FALSE;
// // 	}
// // 	dist[src]=0;
// // 	heap H = buildMinHeap(dist,N_VERT,MIN); //construct the minheap according to the distance
// // 	printHeap(&H);
// //
//
// // 	for(size_t i=0; i<N_VERT; i++)
// // 	{
// //     //u is any N_VERT that is not yet included in visited and has minimum distance
// //     int u=minDist(dist,visited);
// //     //If the N_VERT with minimum distance found include it to visited
// // 		visited[u]=TRUE;
// // 		for(int v=0; v<N_VERT; v++)
// // 		/*Update dist[v] if not in visited and their is a path from src to v through u that has distance minimum than current value of dist[v]*/
// // 		{
// //       /*Relax */
// // 			if(!visited[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
// // 			dist[v]=dist[u]+graph[u][v];
// // 		}
// // 	}
// //
// //   /*Print the output */
// // 	printf("N_VERT\t\tDistance from source \n");
// // 	for(size_t i=0;i<N_VERT;i++)
// //     printf("%ld\t\t %d\n",i, dist[i]);
// //}
//
//
// int main() {
//
//   //adjacency matrix
//   int graph[N_VERT][N_VERT]={{0,1,5,0,0,0,0,0},{0,0,2,3,4,0,0,0},{0,0,0,0,3,3,0,0},{0,0,4,0,0,0,5,0},
//                              {0,0,0,0,0,0,6,0},{0,0,0,0,6,0,0,10},{0,0,0,0,0,0,0,5},{0,0,0,0,0,0,0,0}};
// 	// dijkstra_array(graph,0);
// 	// //dijkstra_heap(graph,0);
//
//
// 	return 0;
// }
