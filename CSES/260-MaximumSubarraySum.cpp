//Maximum Subarray Sum
//Problem: Given an array, find the subarray which yields the largest sum
//Solution: We can use Kadane's algorithm, which performs a linear scan through the array.
//If we are over zero we add the next element, else we start a new subarray with the current element.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int best = nums[0], curr = nums[0];
    for (int i = 1; i < n; i++) {
        if (curr < 0)
            curr = nums[i];
        else
            curr += nums[i];

        best = max(best, curr);
    }

    cout << best << '\n';
}