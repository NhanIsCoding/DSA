#include "Header.h"

void ShowTrunks(Trunk* p) {
    if (p == nullptr)
    {
        return;
    }
    ShowTrunks(p->prev);
    cout << p->str;
}

void DisplayBinTree(Node* root, Trunk* prev, bool isLeft) {
    if (root == nullptr)
    {
        return;
    }
    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);
    DisplayBinTree(root->right, trunk, true);
    if (!prev)
    {
        trunk->str = "---";
    }
    else if (isLeft)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    ShowTrunks(trunk);
    cout << " " << root->data << endl;

    if (prev)
    {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    DisplayBinTree(root->left, trunk, false);
}

int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
        height(y->right)) + 1;
    x->height = max(height(x->left),
        height(x->right)) + 1;

    return x;
}


Node* leftRotate(Node* y) {
    Node* x = y->right;
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max(height(y->left),
        height(y->right)) + 1;
    x->height = max(height(x->left),
        height(x->right)) + 1;

    return x;
}

int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


Node* insertNode(Node* node, int key) {
    if (node == NULL)
        return(newNode(key));

    if (key < node->data)
        node->left = insertNode(node->left, key);
    else if (key > node->data)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
        height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* getMinNode(Node* node) {
    Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node* temp = root->left ?
                root->left :
                root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node* temp = getMinNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,
                temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
        height(root->right));

    int balance = getBalance(root);


    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}