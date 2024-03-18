#include "Header.h"

int main() {
    int* a = NULL;
    int n, Anhcount = 0, Binhcount = 0;
    input(a, n);
    int x;
    cout << "Input x: ";
    cin >> x;
    int index = sequentialSearch(a, n, x, Anhcount);
    if (index == -1) {
        cout << "x not found in the array" << endl;
    }
    else {
        cout << "Found x at index " << index << endl;
    }
    cout << "Anh needs " << Anhcount << " steps" << endl;

    index = binarySearch(a, 0, n - 1, x, Binhcount);
    if (index == -1) {
        cout << "x not found in the array" << endl;
    }
    else {
        cout << "Found x at index " << index << endl;
    }
    cout << "Binh needs " << Binhcount << " steps" << endl;

    compareStep(Anhcount, Binhcount);
    delete[]a;
    return 0;
}