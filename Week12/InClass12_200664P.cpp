
#include <iostream>
using namespace std;
#include <limits.h>


#define V 6

//gives the unvisited vertex with minimum path value
int minDistance(int dist[], bool visited[])
{
	
	int min = INT_MAX; //max value possible
    int min_index;

	for (int v = 0; v < V; v++)
		if (visited[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[], int src)
{
	cout << "Vertex \t Distance from City " << src << " is:"<< endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
    cout << endl;
}


void dijkstra(int graph[V][V], int src)
{
	int distances[V]; 

	bool visited[V]; 

	
	for (int i = 0; i < V; i++)
		distances[i] = INT_MAX, visited[i] = false;

	
	distances[src] = 0;

	
	for (int count = 0; count < V - 1; count++) {
		
		int u = minDistance(distances, visited);

		// Mark the picked vertex as processed
		visited[u] = true;

		
		for (int v = 0; v < V; v++)

			
			if (!visited[v] && graph[u][v]
				&& distances[u] != INT_MAX
				&& distances[u] + graph[u][v] < distances[v])
				distances[v] = distances[u] + graph[u][v];
	}

	
	printSolution(distances, src);
}


int main()
{

	
	int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
                        { 10, 0, 10, 30, 0, 0 },
                        { 0, 10, 0, 12, 5, 0 },
                        { 0, 30, 12, 0, 0, 20 },
                        { 15, 0, 5, 0, 0, 0 },
                        { 5, 0, 0, 20, 0, 0 }, };


	
	dijkstra(graph, 0);
    dijkstra(graph, 1);
    dijkstra(graph, 2);
    dijkstra(graph, 3);
    dijkstra(graph, 4);
    dijkstra(graph, 5);
    

	return 0;
}


