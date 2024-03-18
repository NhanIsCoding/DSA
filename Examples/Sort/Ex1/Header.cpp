#include "Header.h"

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1], * R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] > R[j]) //change to <= if want to ascending
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}


void mergeSort(int arr[], int l, int r) {
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while (true) {
        while (left <= right && arr[left] >= pivot) left++;
        while (right >= left && arr[right] <= pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(int arr[], int low, int high) {
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); //recursion
        quickSort(arr, pi + 1, high);
    }
}

void copyArray(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

void printSortedMax(int* arr) {
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMax(int* arr, int n) {
    int max = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }
    cout << max << " ";
    return index;
}

void deleteElement(int* arr, int& n, int pos) {
    if (n <= 0) {
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    --n;
}

void printMax(int* arr, int n) {
    for (int i = 0; i < 100; i++) {
        int index = findMax(arr, n);
        deleteElement(arr, n, index);
    }
}

void findMintime(double time1, double time2, double time3) {
    if (time1 < time2 && time1 < time3) {
        cout << "Way #1 is the most efficient" << endl;
    }
    if (time2 < time1 && time2 < time3) {
        cout << "Way #2 is the most efficient" << endl;
    }
    if (time3 < time1 && time3 < time2) {
        cout << "Way #3 is the most efficient" << endl;
    }
}