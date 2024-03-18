#include "Header.h"

void printGraph(int no_vertices, int** adj) {
	for (int i = 0; i < no_vertices; i++)
	{
		for (int j = 0; j < no_vertices; j++)
		{
			cout << " " << adj[i][j] << " ";
		}
		cout << "\n";
	}

}

void dfs(int no_vertices, int** adj, int visited[], int start) {
	cout << start << "\t";
	visited[start] = 1;
	for (int i = 0; i < no_vertices; i++)
	{
		if (visited[i] != 1 && adj[start][i] == 1)
		{
			dfs(no_vertices, adj, visited, i);
		}
	}
}

void bfs(int no_vertices, int** adj, int start) {
	int* visited = new int[no_vertices];
	int* queue = new int[no_vertices];
	int front = -1, rear = -1;

	for (int i = 0; i < no_vertices; i++)
		visited[i] = 0;

	front++;
	queue[++rear] = start;
	visited[start] = 1;

	while (front <= rear)
	{
		start = queue[front++];
		cout << start << "\t";

		for (int i = 0; i < no_vertices; i++)
		{
			if (adj[start][i] == 1 && visited[i] != 1)
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}


	}

}