//Array Division
//Problem: Given an array of length n, find the minimum value x such that we can split the array into k subarrays,
//and the max sum of each subarray is lower than or equal to x.
//Solution: We can run a binary search on the answer by trying whether we can do it with the max value being mid or not.
//Then it is a matter of greedily forming the subarrays, by adding to the current subarray until we get past the middle value.
//Note that this works, since if we can make it with (k - 1) subarrays, we can make it with k subarrays.
//Runtime: O(n log(n*x)), where n is the size of the array, and x is the value of the maximum element in the array.
#include <bits/stdc++.h>

using namespace std;

bool possible(vector<long long>& nums, long long k, long long mid) {
    int n = (int)nums.size();
    long long sum = 0LL, count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] + sum > mid) {
            sum = nums[i];
            count++;
        } else {
            sum += nums[i];
        }
    }

    if (sum > 0)
        count++;
    if (count <= k)
        return true;
    return false;
}

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long maxVal = *max_element(nums.begin(), nums.end());

    long long left = maxVal, right = n * maxVal;
    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (possible(nums, k, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (possible(nums, k, left)) {
        cout << left << '\n';
    } else {
        cout << right << '\n';
    }
}