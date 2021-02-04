#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int countPairs(vector<int>& nums, vector<int>& aux, int l, int mid, int r) {
    for (int i = l; i <= r; ++i) {
        aux[i] = nums[i];
    }

    int result = 0;
    int i = l;
    int j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid)
            nums[k] = aux[j++];
        else if (j > r)
            nums[k] = aux[i++];
        else if (aux[i] < aux[j]) {
            nums[k] = aux[i++];
        } else {
            result += mid - i + 1;
            nums[k] = aux[j++];
        }
    }

    return result;
}

int _reversePairs(vector<int>& nums, vector<int>& aux, int l, int r) {
    if (l >= r) return 0;

    int result = 0;
    int mid = l + (r - l) / 2;

    result += _reversePairs(nums, aux, l, mid);
    result += _reversePairs(nums, aux, mid + 1, r);

    if (nums[mid] > nums[mid + 1]) {
        result += countPairs(nums, aux, l, mid, r);
    }

    return result;
}

int reversePairs(vector<int>& nums) {
    vector<int> aux(nums.size());
    return _reversePairs(nums, aux, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {7, 5, 6, 4};
    assert(reversePairs(nums) == 5);

    return 0;
}