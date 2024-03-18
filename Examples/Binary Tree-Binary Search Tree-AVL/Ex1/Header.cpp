#include "Header.h"

void printPostorder(struct Node* node) {
    if (node == NULL)
        return;

    printPostorder(node->left);

    printPostorder(node->right);

    cout << node->data << " ";
}

void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);
}

void printPreorder(struct Node* node) {
    if (node == NULL)
        return;

    cout << node->data << " ";

    printPreorder(node->left);

    printPreorder(node->right);
}

void addNode(Node*& node, int data) {
    node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

bool isBSTFunction(Node* node, int min, int max) {
    if (node == NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return
        isBSTFunction(node->left, min, node->data - 1) && // Allow only distinct values
        isBSTFunction(node->right, node->data + 1, max); // Allow only distinct values
}

void isBST(Node* node) {
    bool check = isBSTFunction(node, INT_MIN, INT_MAX);
    if (check == true) {
        cout << "This is a Binary Search Tree!" << endl;
    }
    else {
        cout << "This is NOT a Binary Search Tree!" << endl;
    }
}