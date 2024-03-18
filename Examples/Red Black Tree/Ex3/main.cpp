#include "Header.h"

int main() {
	node* root = NULL;
	int n;
	int sumValue = 0;
	int nodeCounter = 0;
	insert(root, 10);
	insert(root, 25);
	insert(root, 9);
	insert(root, 49);
	insert(root, 1);
	insert(root, 7);
	nodeCounter = nodeCount(root);
	valueSum(root, sumValue);
	cout << "Tree:" << endl;
	printInorder(root);
	cout << endl;
	cout << "There are " << nodeCounter << " nodes" << endl;
	cout << "Sum value of them is: " << sumValue << endl;

	cout << endl;
	sumValue = 0; //reset

	Delete(root, 10);
	nodeCounter = nodeCount(root);
	valueSum(root, sumValue);
	cout << "After deleting node 10" << endl;
	cout << "Tree:" << endl;
	printInorder(root);
	cout << endl;
	cout << "There are " << nodeCounter << " nodes" << endl;
	cout << "Sum value of them is: " << sumValue << endl;


	return 0;
}