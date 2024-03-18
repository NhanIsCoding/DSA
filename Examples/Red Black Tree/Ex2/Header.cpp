#include "Header.h"

bool checkLeftOfNode(node* l, node* p) {
	if (l == p->left)
		return true; //left of node
	else
		return false; //right of node
}

void swapColor(node* x1, node* x2) {
	char temp = x1->color;
	x1->color = x2->color;
	x2->color = temp;
}

void swapValues(node* u, node* v) {
	int temp = u->data;
	u->data = v->data;
	v->data = temp;
}

void leftRotate(node* x, node*& root) {
	node* newparent = x->right; 
	if (x->data == root->data) {
		root = newparent;
	}
	if (x->parent != NULL)
	{
		if (checkLeftOfNode(x, x->parent))
			x->parent->left = newparent;
		else
			x->parent->right = newparent;
	}
	newparent->parent = x->parent;
	x->parent = newparent;
	x->right = newparent->left;
	if (newparent->left != NULL)
		newparent->left->parent = x;
	newparent->left = x;
}

void rightRotate(node* x, node*& root) {
	node* newparent = x->left;
	if (x->data == root->data)
		root = newparent;
	if (x->parent != NULL)
	{
		if (checkLeftOfNode(x, x->parent))
			x->parent->left = newparent;
		else
			x->parent->right = newparent;
	}
	newparent->parent = x->parent;
	x->parent = newparent;

	x->left = newparent->right;

	if (newparent->right != NULL)
		newparent->right->parent = x;

	newparent->right = x;
}

void searchParent(node* root, node*& temp, int n) {
	if (root == NULL) {
		temp = root;
		return;
	}
	if (root->data == n) {
		temp = root;
		return;
	}
	else if (root->data > n) {
		if (root->left == NULL)
		{
			temp = root;
			return;
		}
		else
			searchParent(root->left, temp, n);
	}
	if (root->data < n) {
		if (root->right == NULL) {
			temp = root;
			return;
		}
		else
			searchParent(root->right, temp, n);
	}
}

node* findNode(node* x, int key) {
	if (x == NULL)
		return NULL;
	if (x->data == key) {
		return x;
	}
	node* p = NULL;
	p = findNode(x->left, key);
	if (p != NULL) {
		return p;
	}
	p = findNode(x->right, key);
	return p;
}

void fixRedRed(node*& x, node*& root) {
	if (x->data == root->data) {
		x->color = 'B';
		return;
	}
	node* parent = x->parent, * grandparent = x->parent->parent;
	node* uncle = NULL;
	if (parent == NULL || grandparent == NULL)
		uncle = NULL;
	else if (checkLeftOfNode(parent, grandparent))
		uncle = grandparent->right;
	else
		uncle = grandparent->left;

	if (parent->color != 'B') {
		if (uncle != NULL && uncle->color == 'R') {
			parent->color = 'B';
			uncle->color = 'B';
			grandparent->color = 'R';
			fixRedRed(x, root);
		}
		else {
			if (checkLeftOfNode(parent, parent->parent)) {
				if (checkLeftOfNode(x, parent))
					swapColor(parent, grandparent);
				else {
					leftRotate(parent, root);
					swapColor(x, grandparent);
				}
				rightRotate(grandparent, root);
			}
			else {
				if (checkLeftOfNode(x, x->parent)) {
					rightRotate(parent, root);
					swapColor(x, grandparent);
				}
				else
					swapColor(parent, grandparent);
				leftRotate(grandparent, root);
			}
		}
	}
}

void insert(node*& root, int n) {
	node* x = new node;
	x->color = 'R';
	x->data = n;
	x->left = NULL;
	x->right = NULL;
	x->parent = NULL;
	if (root == NULL) {
		x->color = 'B';
		root = x;
	}
	else {
		node* temp = NULL;
		searchParent(root, temp, n);//find parent of node x
		if (temp->data == n)
			return;
		x->parent = temp;
		if (temp->data > n)
			temp->left = x;
		else
			temp->right = x;
		fixRedRed(x, root);
	}
}

node* findSibling(node* parent, node* l) {
	if (parent == NULL)
		return NULL;
	if (checkLeftOfNode(l, parent))
		return parent->right;
	else
		return parent->left;
}

bool checkNodehasARedChild(node* l) {
	if ((l->left != NULL && l->left->color == 'R') || (l->right != NULL && l->right->color == 'R'))
		return true;
	return false;
}

node* findTheMostLeftNode(node* x) {
	node* temp = x;
	while (temp->left != NULL)
		temp = temp->left;
	return temp;
}

node* BSTreeplace(node* x) {
	if (x->left != NULL && x->right != NULL)
		return findTheMostLeftNode(x->right);

	if (x->left == NULL && x->right == NULL)
		return NULL;
	if (x->left != NULL)
		return x->left;
	else
		return x->right;
}

void fixDoubleBlack(node* x, node*& root) {
	if (x == root)
		return;
	node* siblingg = findSibling(x->parent, x), * parent = x->parent;
	if (siblingg == NULL)
		fixDoubleBlack(parent, root);
	else {
		if (siblingg->color == 'R') {
			parent->color = 'R';
			siblingg->color = 'B';
			if (checkLeftOfNode(siblingg, siblingg->parent)) {
				rightRotate(parent, root);
			}
			else {
				leftRotate(parent, root);
			}
			fixDoubleBlack(x, root);
		}
		else {
			if (checkNodehasARedChild(siblingg)) {
				if (siblingg->left != NULL && siblingg->left->color == 'R') {
					if (checkLeftOfNode(siblingg, siblingg->parent)) {
						siblingg->left->color = siblingg->color;
						siblingg->color = parent->color;
						rightRotate(parent, root);
					}
					else {
						siblingg->left->color = parent->color;
						rightRotate(siblingg, root);
						leftRotate(parent, root);
					}
				}
				else {
					if (checkLeftOfNode(siblingg, siblingg->parent)) {
						siblingg->right->color = parent->color;
						leftRotate(siblingg, root);
						rightRotate(siblingg, root);
					}
					else {
						siblingg->right->color = siblingg->color;
						siblingg->color = parent->color;
						leftRotate(parent, root);
					}
				}
				parent->color = 'B';
			}
			else {
				siblingg->color = 'R';
				if (parent->color == 'B')
					fixDoubleBlack(parent, root);
				else
					parent->color = 'B';
			}
		}
	}
}

void deleteNode(node*& x, node*& root) {
	node* u = BSTreeplace(x);
	bool uxBlack = ((u == NULL || u->color == 'B') && (x->color == 'B'));
	node* parent = x->parent;

	if (u == NULL) {
		if (x == root) {
			root == NULL;
		}
		else {
			if (uxBlack) {
				fixDoubleBlack(x, root);
			}
			else {
				if (findSibling(x->parent, x) != NULL)
					findSibling(x->parent, x)->color = 'R';
			}
			if (checkLeftOfNode(x, x->parent))
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		delete x;
		return;
	}
	if (x->left == NULL || x->right == NULL) {
		if (x->data == root->data) {
			x->data = u->data;
			x->left = NULL;
			x->right = NULL;
			delete u;
		}
		else {
			if (checkLeftOfNode(x, x->parent)) {
				parent->left = u;
			}
			else
				parent->right = u;
			delete x;
			u->parent = parent;
			if (uxBlack) {
				fixDoubleBlack(u, root);
			}
			else {
				u->color = 'B';
			}
		}
		return;
	}
	swapValues(u, x);
	deleteNode(u, root);
}

void Delete(node*& root, int n) {
	if (root == NULL)
		return;
	node* x = NULL;
	searchParent(root, x, n);
	if (x->data != n) {
		cout << "No available value  " << n << endl;
		return;
	}
	deleteNode(x, root);
}