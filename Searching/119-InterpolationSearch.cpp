//Interpolation Search
//Finds an element in an increasingly ordered array, faster than binary search on average.
//However, it has a stricter requirement than binary search, and it is that numbers should be equally distributed for a faster search.
//Runtime: O(log log n) on average (worst case is O(n))
#include <bits/stdc++.h>

using namespace std;

int InterpolationSearch(const vector<int> &nums, int target) {
    int n = (int)nums.size();
    int low = 0, high = n - 1;
    while ((nums[low] != nums[high]) && (nums[low] <= target) && (target <= nums[high])) {
        int mid = low + ((target - nums[low]) * (high - low) / (nums[high] - nums[low]));

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (target == nums[low]) return low;
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int q;
    cin >> q;
    cout << InterpolationSearch(nums, q);
}