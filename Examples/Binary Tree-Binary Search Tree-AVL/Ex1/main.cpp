#include "Header.h"

int main() {
    Node* root1 = NULL; //the first tree
    addNode(root1, 1);
    /* following is the tree after above statement

             1
            / \
        NULL   NULL
    */

    addNode(root1->left, 2);
    addNode(root1->right, 3);
    /* 2 and 3 become left and right children of 1
                  1
                /   \
                2      3
               / \     / \
            NULL NULL NULL NULL
    */

    addNode(root1->left->left, 4);
    /* 4 becomes left child of 2
       Tree 1:
              1
            /    \
           2      3
          / \     / \
         4 NULL NULL NULL
        / \
      NULL NULL
    */

    cout << "Tree 1:" << endl;
    cout << "Postorder: ";
    printPostorder(root1);
    cout << endl << "Inorder: ";
    printInorder(root1);
    cout << endl << "Preorder: ";
    printPreorder(root1);
    cout << endl;
    isBST(root1);


    Node* root2 = NULL; //make second tree
    addNode(root2, 5);
    /*
        5
       / \
    NULL  NULL
    */
    addNode(root2->right, 7);
    addNode(root2->right->left, 6);
    addNode(root2->left, 2);
    addNode(root2->left->left, 1);
    addNode(root2->left->right, 4);
    /*Tree 2:
                      5
                    /    \
                  /        \
                /            \
               2               7
             /    \            /  \
          1         4          6   NULL
        /   \      /  \       /  \
      NULL  NULL  NULL NULL  NULL NULL
    */
    cout << endl << "Tree 2:" << endl;
    cout << "Postorder: ";
    printPostorder(root2);
    cout << endl << "Inorder: ";
    printInorder(root2);
    cout << endl << "Preorder: ";
    printPreorder(root2);
    cout << endl;
    isBST(root2);

    return 0;
}