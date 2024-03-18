#include "Header.h"

btreenode::btreenode(int t1, bool leaf1) {

	t = t1;

	leaf = leaf1;


	key = new int[2 * t - 1];

	c = new btreenode * [2 * t];

	n = 0;

}

void btreenode::traverse() {

	int i;

	for (i = 0; i < n; i++)

	{

		if (leaf == false)

			c[i]->traverse();

		cout << " " << key[i];

	}

	if (leaf == false)

		c[i]->traverse();

}

void btree::insert(int k) {

	if (root == NULL) {

		root = new btreenode(t, true);

		root->key[0] = k;

		root->n = 1;

	}

	else {

		if (root->n == 2 * t - 1)

		{

			btreenode* s = new btreenode(t, false);

			s->c[0] = root;

			s->splitChild(0, root);

			int i = 0;

			if (s->key[0] < k)

				i++;

			s->c[i]->insertNonfull(k);

			root = s;

		}

		else

			root->insertNonfull(k);

	}

}

void btreenode::insertNonfull(int k) {
	int i = n - 1;

	if (leaf == true) {

		while (i >= 0 && key[i] > k)

		{

			key[i + 1] = key[i];

			i--;

		}

		key[i + 1] = k;

		n = n + 1;

	}

	else {

		while (i >= 0 && key[i] > k)

			i--;

		if (c[i + 1]->n == 2 * t - 1)

		{

			splitChild(i + 1, c[i + 1]);

			if (key[i + 1] < k)

				i++;

		}

		c[i + 1]->insertNonfull(k);

	}

}

void btreenode::splitChild(int i, btreenode* y) {

	btreenode* z = new btreenode(y->t, y->leaf);

	z->n = t - 1;

	for (int j = 0; j < t - 1; j++)

		z->key[j] = y->key[j + t];

	if (y->leaf == false)

	{

		for (int j = 0; j < t; j++)

			z->c[j] = y->c[j + t];

	}

	y->n = t - 1;

	for (int j = n; j >= i + 1; j--)

		c[j + 1] = c[j];

	c[i + 1] = z;

	for (int j = n - 1; j >= i; j--)

		key[j + 1] = key[j];

	key[i] = y->key[t - 1];


	n = n + 1;

}