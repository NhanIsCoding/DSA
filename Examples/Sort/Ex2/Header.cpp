#include "Header.h"


void input(int* a, int n) {
	cout << "Please input the elements:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << endl;
}

bool isPrime(int n) {
	if (n <= 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

void Sort(int a[], int n, bool* check) {
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i]) == true) {
			check[i] = 1;
		}
		else check[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j] && check[i] == 0 && check[j] == 0)
				swap(a[i], a[j]);
			if (a[i] > a[j] && check[i] == 1 && check[j] == 1)
				swap(a[i], a[j]);
		}
	}
}

void output(int* a, int n) {
	cout << "After sorting: " << endl;
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}