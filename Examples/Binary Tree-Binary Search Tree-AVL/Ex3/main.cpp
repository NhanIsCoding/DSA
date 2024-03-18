#include "Header.h"

int main() {
    Node* root = NULL;
    int choice;
    int n;
    while (true) {
        cout << "1.Insert Node" << endl;
        cout << "2.Delete Node" << endl;
        cout << "3.Print out the tree" << endl;
        do {
            cout << "Input the function you want to use (1 to 3): ";
            cin >> choice;
            if (choice != 1 && choice != 2 && choice != 3) {
                cout << "Please input again" << endl;;
            }
        } while (choice != 1 && choice != 2 && choice != 3);
        switch (choice) {
        case 1:
            cout << "Input the key value to insert: ";
            cin >> n;
            root = insertNode(root, n);
            cout << "Key " << n << " is inserted to the tree" << endl;
            break;
        case 2:
            cout << "Input the key value to delete: ";
            cin >> n;
            root = deleteNode(root, n);
            cout << "Key " << n << " is deleted from the tree" << endl;
            break;
        case 3:
            cout << endl;
            DisplayBinTree(root, nullptr, false);
            cout << endl;
            break;
        }

        cout << "Do you want to continue using the functions?" << endl;
        cout << "Input 1 if yes, or input any key if no: ";
        cin >> choice;
        if (choice != 1) {
            break;
        }

    }
    return 0;
}