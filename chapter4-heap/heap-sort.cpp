#include <algorithm>
#include <iostream>

#include "../chapter2-sorting-basic/SortTestHelper.h"
#include "MaxHeap.h"

template <typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<T> maxHeap;

    for (int i = 0; i < n; ++i) {
        maxHeap.insert(arr[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        arr[i] = maxHeap.extractMax();
    }
}

template <typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<T> maxHeap(arr, n);

    for (int i = n - 1; i >= 0; --i) {
        arr[i] = maxHeap.extractMax();
    }
}

template <typename T>
void __shiftDown(T arr[], int n, int k) {
    while (2 * k + 1 < n) {
        int j = 2 * k + 1;

        if (j + 1 < n && arr[j + 1] > arr[j]) ++j;

        if (arr[k] >= arr[j]) break;

        swap(arr[k], arr[j]);

        k = j;
    }
}

template <typename T>
void heapSort3(T arr[], int n) {
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

int main() {
    int n = 1e6;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr3 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr4 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr5 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr6 = SortTestHelper::generateRandomArray(n, 0, n);

    assert(SortTestHelper::isSorted(arr1, n) == false);

    heapSort1(arr1, n);

    assert(SortTestHelper::isSorted(arr1, n) == true);

    SortTestHelper::testSort("heapSort", heapSort1, arr2, n);

    assert(SortTestHelper::isSorted(arr3, n) == false);

    heapSort2(arr3, n);

    assert(SortTestHelper::isSorted(arr3, n) == true);

    SortTestHelper::testSort("heapSort", heapSort2, arr4, n);

    assert(SortTestHelper::isSorted(arr5, n) == false);

    heapSort3(arr5, n);

    assert(SortTestHelper::isSorted(arr5, n) == true);

    SortTestHelper::testSort("heapSort", heapSort3, arr6, n);
}