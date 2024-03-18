#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

struct List {
    node* head;
};

void init(List& list);
void printList(List& list);
void addHead(List& list, int x);
void addTail(List& list, int x);
void input(List& list, int n, int x);
node* merge(node* firstNode, node* secondNode);
node* middle(node* head);
node* sortLinkedList(node* head);


#endif