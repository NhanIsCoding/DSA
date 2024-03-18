#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void printPostorder(struct Node* node);
void printInorder(struct Node* node);
void printPreorder(struct Node* node);
void addNode(Node*& node, int data);
bool isBSTFunction(Node* node, int min, int max);
void isBST(Node* node);


#endif