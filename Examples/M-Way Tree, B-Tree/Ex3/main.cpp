#include "Header.h"

int main()
{
	btree  b;
	int choice, key, flag;
	while (1)
	{
		cout << "\n\nMain Menu\n-------------" << endl;
		cout << "1.Insert an element" << endl;
		cout << "2.Search for an element" << endl;
		cout << "3.Display the Tree" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter Choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:	cout << "Enter the integer to be inserted: ";
			cin >> key;
			b.insert(key);
			break;
		case 2:	cout << "Enter the integer to be found: ";
			cin >> key;
			flag = b.search(key);
			if (flag)
				cout << "Element exists in B-tree" << endl;
			else
				cout << "Element not found in B-tree" << endl;
			break;
		case 3: b.display();
			break;
		default:cout << "Thank you for using the program, goodbye" << endl;
			exit(0);
		}
	}
}