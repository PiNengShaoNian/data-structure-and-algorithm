#include <iostream>

#include "../chapter2-sorting-basic/SortTestHelper.h"
#include "assert.h"

template <typename T>
void merge(int lo, int mid, int hi, T arr[], T aux[]) {
    for (int i = lo; i <= hi; ++i) {
        aux[i] = arr[i];
    }

    int index1 = lo;
    int index2 = mid + 1;

    for (int i = lo; i <= hi; ++i) {
        if (index1 > mid)
            arr[i] = arr[index2++];
        else if (index2 > hi)
            arr[i] = arr[index1++];
        else if (arr[index1] < arr[index2]) {
            arr[i] = arr[index1++];
        } else
            arr[i] = arr[index2++];
    }
}

template <typename T>
void mergeSort(T arr[], int lo, int hi, T aux[]) {
    if (lo >= hi) return;

    int mid = lo + (hi - lo) / 2;

    mergeSort(arr, lo, mid, aux);
    mergeSort(arr, mid + 1, hi, aux);

    if (arr[mid] <= arr[mid + 1]) return;

    merge(lo, mid, hi, arr, aux);
}

template <typename T>
void mergeSort(T arr[], int n) {
    T *aux = new T[n];

    mergeSort(arr, 0, n - 1, aux);

    delete[] aux;
}

template <typename T>
void mergeSortBU(T arr[], int n) {
    T *aux = new T[n];

    for (int size = 1; size <= n; size += size) {
        for (int i = 0; i + size < n; i += size + size) {
            merge(i, i + size - 1, min(i + size + size - 1, n - 1), arr, aux);
        }
    }

    mergeSort(arr, 0, n - 1, aux);

    delete[] aux;
}

int main() {
    int n = 1e6;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    assert(SortTestHelper::isSorted(arr, n) == false);
    mergeSort(arr, n);

    assert(SortTestHelper::isSorted(arr, n) == true);

    int *arr2 = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("mergeSort", mergeSort, arr2, n);

    int *arr3 = SortTestHelper::generateRandomArray(n, 0, n);

    assert(SortTestHelper::isSorted(arr3, n) == false);
    mergeSortBU(arr3, n);
    assert(SortTestHelper::isSorted(arr3, n) == true);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
}