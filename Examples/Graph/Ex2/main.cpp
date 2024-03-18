#include "Header.h"

int main() {
	int no_vertices = 0;
	int s = 0, d = 0, ch, start;
	cout << "Enter the number of vertices : ";
	cin >> no_vertices;
	int** adj = new int* [no_vertices]; //make a matrix
	for (int i = 0; i < no_vertices; i++) {
		adj[i] = new int[no_vertices];
	}
	int* visited = new int[no_vertices];

	for (int i = 0; i < no_vertices; i++)
		for (int j = 0; j < no_vertices; j++)
			adj[i][j] = 0;

	while (s != -1 && d != -1) {
		cout << "Enter an Edge from Node(0 to " << no_vertices << ") to Node(0 to " << no_vertices - 1 << "): ";
		cin >> s;
		cin >> d;
		if (s == -1 || d == -1) {
			break;
		}
		adj[s][d] = 1;
		adj[d][s] = 1;
	}

	cout << "The Adjacency Matrix of this Graph is:" << endl;
	printGraph(no_vertices, adj);
	checkEdge(s, d, adj);
	return 0;
}