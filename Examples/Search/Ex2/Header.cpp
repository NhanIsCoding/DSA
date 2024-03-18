#include "Header.h"

void input(int*& a, int& n, int& x) {
    cout << "Input n: ";
    cin >> n;
    n++; //make a space to insert an integer
    a = new int[n];
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    cout << "Input x: ";
    cin >> x;
}

int binarySearch(int* a, int l, int r, int target) {
    int pre = -1;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] < target) {
            l = mid + 1;
            pre = mid + 1;
        }
        else {
            pre = mid;
            r = mid - 1;
        }
    }
    return pre;
}

void insert(int*& a, int n, int index, int x) {
    for (int i = n - 1; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = x;
}

void print(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}