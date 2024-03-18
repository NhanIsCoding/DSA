#include "Header.h"

int main() {
    BTree* r = NULL, * np = NULL, * x = NULL;
    int n;
    int choice;
    cout << "This is the program to test insert function" << endl;
    while (true) {
        cout << "Enter the element: ";
        cin >> n;
        insert(r,np,x,n);
        cout << "Traversal of this B-tree: " << endl;
        traverseBtree(r);
        do {
            cout << "Do you want to continue inserting?" << endl;
            cout << "Input 1 if Yes, 0 if No: ";
            cin >> choice;
            if (choice != 0 && choice != 1) {
                cout << "Please input again!" << endl;
            }
        } while (choice != 0 && choice != 1);
        if (choice == 0) {
            cout << "Thank you for using the program, goodbye" << endl;
            break;
        }
    }
    return 0;

}