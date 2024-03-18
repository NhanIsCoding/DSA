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

int max(int a, int b) {
    return (a >= b) ? a : b;
}


int height(Node* node) {
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(Node* root) {
    int leftHeight;
    int rightHeight;

    if (root == NULL)
        return 1;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        addNode(node, data);
    }
    else if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else {
        node->right = insert(node->right, data);
    }
    return node;
}

int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}