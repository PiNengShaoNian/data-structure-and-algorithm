#include <algorithm>

#include "../chapter2-sorting-basic/SortTestHelper.h"

using namespace std;

template <typename T>
int partition(T arr[], int l, int r) {
    int v = arr[l];
    int i = l;
    int j = r + 1;

    while (true) {
        while (arr[++i] < v)
            if (i >= r) break;

        while (arr[--j] > v)
            if (j <= l) break;

        if (i >= j) break;

        swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);

    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r) return;

    int p = partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
    return __quickSort(arr, 0, n - 1);
}

template <typename T>
void _quickSort3Ways(T arr[], int l, int r) {
    if (l >= r) return;

    T v = arr[l];
    int lt = l;
    int gt = r + 1;
    int i = l + 1;

    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[lt + 1], arr[i]);
            ++lt;
            ++i;
        } else if (arr[i] > v) {
            swap(arr[i], arr[gt - 1]);
            --gt;
        } else {
            ++i;
        }
    }

    swap(arr[l], arr[lt]);

    _quickSort3Ways(arr, l, lt - 1);
    _quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n) {
    _quickSort3Ways(arr, 0, n - 1);
}

int main() {
    int n = 1e6;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    assert(SortTestHelper::isSorted(arr, n) == false);
    quickSort(arr, n);

    assert(SortTestHelper::isSorted(arr, n) == true);

    int *arr2 = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("quickSort", quickSort, arr2, n);

    int *arr3 = SortTestHelper::generateRandomArray(n, 0, n);

    assert(SortTestHelper::isSorted(arr3, n) == false);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
}