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

void checkEdge(int s, int d, int** adj) {
	while (true) {
		cout << "Enter 2 nodes to check if they have an Edge: ";
		cin >> s;
		cin >> d;
		if (s == -1 || d == -1) {
			break;
		}
		if (adj[s][d] == 1) {  //adj[d][s]==1
			cout << "They have an Edge!" << endl;
		}
		else {
			cout << "They do NOT have an Edge" << endl;
		}
	}
	cout << "Thank you for using the program" << endl;
}