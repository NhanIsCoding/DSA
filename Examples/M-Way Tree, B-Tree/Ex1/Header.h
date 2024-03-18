#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;

// A class to create a node 

class btreenode {
	int* key;
	int t;
	btreenode** c;
	int n;
	bool leaf;

public:

	btreenode(int _t, bool _leaf);
	void insertNonfull(int k);
	void splitChild(int i, btreenode* y);
	void traverse();
	btreenode* search(int k);
	friend class btree;
};

// class btree

class btree {

	btreenode* root;

	int t;

public:


	btree(int _t)

	{

		root = NULL;

		t = _t;

	}


	void traverse()

	{
		if (root != NULL)

			root->traverse();

	}

	void insert(int k);
};






#endif