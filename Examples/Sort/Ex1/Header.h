#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void copyArray(int a[], int b[], int n);
void printSortedMax(int* arr);
int findMax(int* arr, int n);
void deleteElement(int* arr, int& n, int pos);
void printMax(int* arr, int n);
void findMintime(double time1, double time2, double time3);



#endif