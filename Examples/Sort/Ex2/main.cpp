#include "Header.h"

int main() {
	int* a = NULL;
	int n;
	cout << "Please input the number of elements n: ";
	cin >> n;
	a = new int[n];
	bool* check = new bool[n];
	input(a, n);
	Sort(a, n, check);
	output(a, n);
	delete[]a;
	delete[]check;
	return 0;
}