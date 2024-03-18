#include "Header.h"

int main() {
    int n = 1000000;
    int* randArray1 = new int[n];
    int* randArray2 = new int[n];
    int* randArray3 = new int[n];
    for (int i = 0; i < n; i++) {
        randArray1[i] = rand() % 1000000; //generate number between 0 to 999999
    }
    copyArray(randArray1, randArray2, n);
    copyArray(randArray1, randArray3, n);

    auto t_start = high_resolution_clock::now();
    mergeSort(randArray1, 0, n - 1);
    cout << "Way #1 " << endl;
    cout << "Max elements:(Merge sort)" << endl;
    printSortedMax(randArray1);
    auto t_end = high_resolution_clock::now();
    double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    cout << "This way takes: " << elapsed_time_ms / 1000 << " seconds" << endl;
    cout << endl;
    double time1 = elapsed_time_ms;

    t_start = high_resolution_clock::now();
    quickSort(randArray2, 0, n - 1);
    cout << "Way #2 " << endl;
    cout << "Max elements: (Quick sort)" << endl;
    printSortedMax(randArray2);
    t_end = high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    cout << "This way takes: " << elapsed_time_ms / 1000 << " seconds" << endl;
    cout << endl;
    double time2 = elapsed_time_ms;

    t_start = high_resolution_clock::now();
    cout << "Way #3 " << endl;
    cout << "Max elements: (Sequential search)" << endl;
    printMax(randArray3, n);
    t_end = high_resolution_clock::now();
    elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();
    cout << "This way takes: " << elapsed_time_ms / 1000 << " seconds" << endl;
    double time3 = elapsed_time_ms;

    findMintime(time1, time2, time3);


    delete[]randArray1;
    delete[]randArray2;
    delete[]randArray3;
    return 0;
}