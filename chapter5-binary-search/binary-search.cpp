#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool binarySearch(T arr[], int n, const T& target) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
            return true;
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return false;
}

template <class ForwardIt, class T>
ForwardIt leftBound(ForwardIt first, ForwardIt last, const T& target) {
    ForwardIt l = first;
    ForwardIt r = last - 1;

    while (l <= r) {
        ForwardIt mid = l + (r - l) / 2;

        if (*mid == target) {
            r = mid - 1;
        } else if (*mid > target) {
            r = mid - 1;
        } else if (*mid < target) {
            l = mid + 1;
        }
    }

    if (l >= last || *l != target) l = last;

    return l;
}

int main() {
    int arr1[] = {1, 2, 3, 3, 3, 4, 5, 6};
    assert(binarySearch(arr1, sizeof(arr1) / sizeof(int), 1) == true);
    assert(binarySearch(arr1, sizeof(arr1) / sizeof(int), 6) == true);
    assert(binarySearch(arr1, sizeof(arr1) / sizeof(int), 3) == true);
    assert(binarySearch(arr1, sizeof(arr1) / sizeof(int), 0) == false);
    assert(binarySearch(arr1, sizeof(arr1) / sizeof(int), 7) == false);

    assert(leftBound(cbegin(arr1), cend(arr1), 3) == arr1 + 2);
    assert(leftBound(cbegin(arr1), cend(arr1), 1) == arr1);
    assert(leftBound(cbegin(arr1), cend(arr1), 6) == cend(arr1) - 1);
}