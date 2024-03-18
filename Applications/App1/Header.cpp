#include "Header.h"

bool is_file_exist(string fileName) {
    ifstream infile(fileName);
    return infile.good();
}

int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(string id, string name, string birth, bool gender, bool status) {
    Node* node = new Node();
    node->id = id;
    node->name = name;
    node->birth = birth;
    node->gender = gender;
    node->status = status;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
                      // added at leaf
    return(node);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
        height(y->right)) + 1;
    x->height = max(height(x->left),
        height(x->right)) + 1;

    // Return new root
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
        height(x->right)) + 1;
    y->height = max(height(y->left),
        height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


Node* insertNode(Node* node, string id, string name, string birth, bool gender, bool status) {
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(id, name, birth, gender, status));

    if (name < node->name)
        node->left = insertNode(node->left, id, name, birth, gender, status);
    else if (name > node->name)
        node->right = insertNode(node->right, id, name, birth, gender, status);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
        height(node->right));

    int balance = getBalance(node);


    // Left Left Case
    if (balance > 1 && name < node->left->name)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && name > node->right->name)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && name > node->left->name)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && name < node->right->name)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void Loadfile(Node*& root, int& n) {
    string id;
    string name;
    string birth;
    bool gender;
    bool status;
    ifstream fin;
    fin.open("employee.txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {

            fin >> id;
            fin.ignore();
            getline(fin, name, '\n');
            fin >> birth;
            fin >> gender;
            fin >> status;
            root = insertNode(root, id, name, birth, gender, status);
        }
    }
    fin.close();
}

void printInorder(struct Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << "ID: ";
    cout << node->id << endl;
    cout << "Name: ";
    cout << node->name << endl;
    cout << "Birthday: ";
    cout << node->birth << endl;
    cout << "Gender: ";
    if (node->gender == 0) {
        cout << "Female" << endl;
    }
    else {
        cout << "Male" << endl;
    }
    cout << "Status: ";
    if (node->status == 0) {
        cout << "Working" << endl;
    }
    else {
        cout << "Quitted" << endl;
    }
    printInorder(node->right);
}

Node* findNode(Node* node, string key) {
    if (node == NULL)
        return NULL;
    if (node->id == key) {
        return node;
    }
    Node* p = NULL;
    p = findNode(node->left, key);
    if (p != NULL) {
        return p;
    }
    p = findNode(node->right, key);
    return p;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}


Node* deleteNode(Node* root, string key) {

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;


    if (key < root->name)
        root->left = deleteNode(root->left, key);


    else if (key > root->name)
        root->right = deleteNode(root->right, key);

    else
    {
        // node with only one child or no child
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node* temp = root->left ?
                root->left :
                root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's
            // data to this node
            root->name = temp->name;

            // Delete the inorder successor
            root->right = deleteNode(root->right,
                temp->name);
        }
    }


    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
        height(root->right));


    int balance = getBalance(root);


    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printWorkStaff(Node* node) {
    if (node == NULL)
        return;
    printWorkStaff(node->left);
    if (node->status == 0) { //still working
        cout << node->id << endl;
        cout << node->name << endl;
        cout << node->birth << endl;
        if (node->gender == 0) {
            cout << "Female" << endl;
        }
        else {
            cout << "Male" << endl;
        }
    }
    printWorkStaff(node->right);
}

void deleteQuitStaff(Node* root, Node* p) { //Left Right Node so that we can delete from child nodes
    if (p == NULL) {
        return;
    }

    deleteQuitStaff(root, p->left);
    deleteQuitStaff(root, p->right);
    if (p->status == 1) {
        root = deleteNode(root, p->name);
    }
}

int nodeCount(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

void printFileInorder(struct Node* node, ofstream& fout) {
    if (node == NULL)
        return;
    printFileInorder(node->left, fout);
    fout << node->id << endl;
    fout << node->name << endl;
    fout << node->birth << endl;
    fout << node->gender << endl;
    fout << node->status << endl;
    printFileInorder(node->right, fout);
}

void Savefile(Node* root, int n) {
    ofstream fout;
    fout.open("employee.txt");
    if (fout.is_open()) {
        fout << n << endl;;
        printFileInorder(root, fout);
    }
    fout.close();
}