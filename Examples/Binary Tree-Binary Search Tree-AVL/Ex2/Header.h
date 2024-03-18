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
int max(int a, int b);
int height(Node* node);
bool isBalanced(Node* root);
Node* insert(Node* node, int data);
int findMin(Node* root);
int findMax(Node* root);


#endif