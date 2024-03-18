#include "Header.h"

int main() {
    int* a = NULL;
    int n;
    int x;
    input(a, n, x);
    int index = binarySearch(a, 0, n - 1 - 1, x);
    cout << "Index to insert x is " << index << endl;
    insert(a, n, index, x);
    cout << "Array: " << endl;
    print(a, n);
    delete[]a;
}