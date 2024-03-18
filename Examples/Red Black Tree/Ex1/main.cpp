#include "Header.h"

int main() {
	node* root = NULL;
	node* temp = NULL;
	int n;
	int choice;
	insert(root, 10);
	insert(root, 25);
	insert(root, 9);
	insert(root, 49);
	insert(root, 1);
	insert(root, 7);

	while (true)
	{
		cout << "Input a value to find in Red-Black Tree: ";
		cin >> n;
		temp=findNode(root, n);
		if (temp!=NULL)
			cout << n << " is in the Red-Black Tree!" << endl;
		else {
			cout << n << " is Not Found in Red Black-Tree!" << endl;
			cout << "Do you want to insert " << n << " to the Tree?" << endl;
			cout << "Input 1 if Yes,0 if No" << endl;
			do {
				cin >> choice;
				if (choice != 0 && choice != 1) {
					cout << "Please input 1 if Yes,0 if No" << endl;
				}
			} while (choice != 0 && choice != 1);
			if (choice == 1) {
				insert(root, n);
				cout << n << " is inserted!" << endl;
			}
		}
		cout << "Do you want to continue searching some nodes?" << endl;
		cout << "Input 1 if Yes,0 if no" << endl;
		do {
			cin >> choice; 
			if (choice != 0 && choice != 1) {
				cout << "Please input 1 if Yes,0 if No" << endl;
			}
		} while (choice != 0 && choice != 1);
		if (choice == 0) {
			cout << "Thank you for using the program, goodbye" << endl;
			break;
		}
	}

	return 0;
}
