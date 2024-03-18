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

	while (s != -1 && d != -1)
	{
		cout << "Enter an Edge from Node(0 to " << no_vertices << ") to Node(0 to " << no_vertices - 1 << "): ";
		cin >> s;
		cin >> d;
		if (s == -1 || d == -1) {
			break;
		}
		adj[s][d] = 1;
		adj[d][s] = 1;
	}

	do
	{
		cout << "\nEnter 1 for BFS\nEnter 2 for DFS\nEnter 3 for printing adjacency matrix\nEnter 4 to Exit : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter the Vertex fron which do you wanted to start : ";
			cin >> start;
			bfs(no_vertices, adj, start); break;
		case 2:
			cout << "Enter the Vertex fron which do you wanted to start : ";
			cin >> start;
			for (int i = 0; i < no_vertices; i++)
				visited[i] = 0;
			dfs(no_vertices, adj, visited, start); break;

			break;
		case 3:printGraph(no_vertices, adj); break;
		case 4:
			cout << "Thank you for using the program, goodbye" << endl;
			break;
		}

	} while (ch != 4);

	return 0;
}