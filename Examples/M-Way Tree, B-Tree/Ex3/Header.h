#ifndef _HEADER_H_
#define _HEADER_H_

#define MAX 4			
#define MIN 2
#include<iostream>
using namespace std;

struct node
{
	int ele[MAX];
	struct node* child[MAX];
	struct node* parent;
};
typedef struct node* NODE;

class btree
{
	NODE root;
public:
	btree()
	{
		root = create_newnode();
	}
	void insert(int);
	int search(int);
	void display();
	int isFull(NODE);
	NODE create_newnode();
	NODE find_leaf(NODE, int);
	void split(NODE);
	void sort_node(NODE);
	void update_parent(NODE, int, int);
};


#endif