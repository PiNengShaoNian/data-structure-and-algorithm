#include <assert.h>

#include <algorithm>
#include <iostream>

#include "SortTestHelper.h"
#include "Student.h"

using namespace std;

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int a[] = {10, 3, 24, 1, 5, 6};
    Student b[] = {{"a", 6}, {"b", 55}, {"c", 33}, {"D", 39}};

    int len = sizeof(a) / sizeof(int);
    selectionSort(a, len);
    selectionSort(b, sizeof(b) / sizeof(Student));
    selectionSort(arr, n);
    assert(SortTestHelper::isSorted(a, sizeof(a) / sizeof(int)) == true);
    assert(SortTestHelper::isSorted(b, sizeof(b) / sizeof(Student)) == true);

    SortTestHelper::testSort("selectionSort", selectionSort, arr, n);
    delete[] arr;
    return 0;
}