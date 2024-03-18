#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

struct Trunk {
    Trunk* prev;
    string str;
    Trunk(Trunk* prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void ShowTrunks(Trunk* p);
void DisplayBinTree(Node* root, Trunk* prev, bool isLeft);
int height(Node* N);
int max(int a, int b);
Node* newNode(int key);
Node* rightRotate(Node* y);
Node* leftRotate(Node* y);
int getBalance(Node* N);
Node* insertNode(Node* node, int key);
Node* getMinNode(Node* node);
Node* deleteNode(Node* root, int key);



#endif