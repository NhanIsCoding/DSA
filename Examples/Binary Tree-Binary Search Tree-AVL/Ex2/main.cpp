#include "Header.h"

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    bool checkBalance;

    root1 = insert(root1, 4);
    root1 = insert(root1, 2);
    root1 = insert(root1, 6);
    root1 = insert(root1, 1);
    root1 = insert(root1, 13);
    root1 = insert(root1, 7);
    root1 = insert(root1, 9);

    root2 = insert(root2, 6);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);
    root2 = insert(root2, 7);
    root2 = insert(root2, 10);
    root2 = insert(root2, 3);
    root2 = insert(root2, 5);

    cout << "PreOrder of root1: ";
    printPreorder(root1);
    cout << endl;
    cout << "Tree1 height is: " << height(root1) << endl;
    checkBalance = isBalanced(root1);
    if (checkBalance == true) {
        cout << "This is a balanced tree!" << endl;
    }
    else {
        cout << "This is NOT a balanced tree!" << endl;
    }
    cout << "Max of root1 is: " << findMax(root1) << endl;
    cout << "Min of root1 is: " << findMin(root1) << endl;

    cout << "PreOrder of root2: ";
    printPreorder(root2);
    cout << endl;
    cout << "Tree2 height is: " << height(root2) << endl;
    checkBalance = isBalanced(root2);
    if (checkBalance == true) {
        cout << "This is a balanced tree!" << endl;
    }
    else {
        cout << "This is NOT a balanced tree!" << endl;
    }
    cout << "Max of root2 is: " << findMax(root2) << endl;
    cout << "Min of root2 is: " << findMin(root2) << endl;

    return 0;
}