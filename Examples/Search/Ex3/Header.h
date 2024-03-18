#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;

void printBoard(int board[][16], int n);
bool valid(int board[][16], int row, int col, int n);
bool solve16Queen(int board[][16], int col, int n);
bool TryQueen(int board[][16], int n);



#endif