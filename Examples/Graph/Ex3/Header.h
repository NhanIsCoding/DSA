#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
using namespace std;

void printGraph(int no_vertices, int** adj);
void dfs(int no_vertices, int** adj, int visited[], int start);
void bfs(int no_vertices, int** adj, int start);


#endif