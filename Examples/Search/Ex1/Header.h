#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
using namespace std;

void input(int*& a, int& n);
int sequentialSearch(int* a, int n, int x, int& count);
int binarySearch(int* a, int l, int r, int x, int& count);
void compareStep(int a, int b);



#endif