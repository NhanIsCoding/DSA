#include "Header.h"

void input(int*& a, int& n) {
    cout << "Input the number of elements: ";
    cin >> n;
    a = new int[n];
    cout << "Input the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int sequentialSearch(int* a, int n, int x, int& count) {
    int i;
    for (i = 0; i < n; i++) {
        count++;
        if (a[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(int* a, int l, int r, int x, int& count) {
    while (l <= r) {
        count++;
        int m = l + (r - l) / 2;

        if (a[m] == x)
            return m;

        if (a[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

void compareStep(int a, int b) {
    if (a > b) {
        cout << "Linear search needs more steps in this case" << endl;
    }
    if (a < b) {
        cout << "Binary search needs more steps in this case" << endl;
    }
    if (a == b) {
        cout << "The steps are equal!" << endl;
    }
}