#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
using namespace std;

struct node {
	int data;
	char color;// R for Red, B for Black
	node* left;
	node* right;
	node* parent;
};

bool checkLeftOfNode(node* l, node* p);
void swapColor(node* x1, node* x2);
void swapValues(node* u, node* v);
void leftRotate(node* x, node*& root);
void rightRotate(node* x, node*& root);
void searchParent(node* root, node*& temp, int n);
node* findNode(node* node, int key);
void fixRedRed(node*& x, node*& root);
void insert(node*& root, int n);
node* findSibling(node* parent, node* l);
bool checkNodehasARedChild(node* l);
node* findTheMostLeftNode(node* x);
node* BSTreeplace(node* x);
void fixDoubleBlack(node* x, node*& root);
void deleteNode(node*& x, node*& root);
void Delete(node*& root, int n);
int nodeCount(node* root);
void valueSum(node* root, int& sum);
void printInorder(node* root);




#endif