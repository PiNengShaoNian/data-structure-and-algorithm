#include <algorithm>
#include <cassert>
#include <iostream>

#include "SortTestHelper.h"

template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T temp = arr[i];
        int j = i;
        while (j >= 1 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = temp;
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    assert(SortTestHelper::isSorted(arr, n) == false);
    insertionSort(arr, n);

    assert(SortTestHelper::isSorted(arr, n) == true);

    int *arr2 = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("InsertionSort", insertionSort, arr2, n);

    delete[] arr;
    delete[] arr2;
}