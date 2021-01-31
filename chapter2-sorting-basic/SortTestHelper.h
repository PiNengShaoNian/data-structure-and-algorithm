#ifndef CHAPTER_ONE_SORT_TEST_HELPER
#define CHAPTER_ONE_SORT_TEST_HELPER

#include <assert.h>
#include <time.h>

#include <iostream>
#include <string>

using namespace std;

namespace SortTestHelper {
int *generateRandomArray(int n, int rangeL, int rangeR) {
    assert(rangeL <= rangeR);

    int *arr = new int[n];
    srand(time(NULL));

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
    return arr;
}

int *generateNearlyOrderedArray(int n, int swapTimes) {
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < swapTimes; ++i) {
        int posx = rand() % n;
        int posy = rand() % n;
        swap(arr[posx], arr[posy]);
    }

    return arr;
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return;
}

template <typename T>
void testSort(string sortName, void (*sort)(T[], int), T arr[], int n) {
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();

    cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC
         << " s" << endl;
}

template <typename T>
bool isSorted(T arr[], int n) {
    for (int i = 0; i + 1 < n; ++i) {
        if (arr[i + 1] < arr[i]) return false;
    }

    return true;
}
}  // namespace SortTestHelper
#endif