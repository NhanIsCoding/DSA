#include "Header.h"

int main() {
	btree p(3); // A B-Tree with minium degree 3

	p.insert(10);
	p.insert(7);
	p.insert(9);
	p.insert(15);
	p.insert(23);
	p.insert(13);
	p.insert(35);
	p.insert(1);

	cout << "Traversal of this B-tree is: ";

	p.traverse();

	return 0;

}