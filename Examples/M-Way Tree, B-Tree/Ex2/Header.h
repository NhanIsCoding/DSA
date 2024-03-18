#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;

struct BTree {
    int* d;
    BTree** childPointer;
    bool l;
    int n;
};

BTree* init(BTree*& r, BTree*& np, BTree*& x);
void sort(int* p, int n);
int splitChild(BTree*& r, BTree*& np, BTree*& x, int i);
void insert(BTree*& r, BTree*& np, BTree*& x, int a);
void traverseBtree(BTree* p);





#endif