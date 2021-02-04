#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int l, int r) {
    int v = nums[l];
    int i = l;
    int j = r + 1;

    while (true) {
        while (nums[++i] < v)
            if (i >= r) break;

        while (nums[--j] > v)
            if (j <= l) break;

        if (i >= j) break;

        swap(nums[i], nums[j]);
    }

    swap(nums[l], nums[j]);
    return j;
}

int smallestK(vector<int> &nums, int k) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
        int mid = partition(nums, l, r);

        if (mid == k)
            break;
        else if (mid < k)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return nums[k];
}

int main() {
    vector<int> nums = {6, 3, 5, 2, 4, 1};
    assert(smallestK(nums, 0) == 1);
    assert(smallestK(nums, 1) == 2);
    assert(smallestK(nums, 2) == 3);
    assert(smallestK(nums, 3) == 4);
    assert(smallestK(nums, 4) == 5);
}