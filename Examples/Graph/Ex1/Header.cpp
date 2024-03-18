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