//Sum Of Three Values
//Problem: Given an array, find the positions of three distinct elements such that their sum is x, or report it is not possible.
//Solution: We can sort the elements, and then try for every index if we can form x - arr[i] or not.
//To find this out, we can use the two pointers method, on which we decrease the right pointer if the sum is too great,
//or increase the left one if it is too small.
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l != r) {
            int target = x - nums[i].first;
            int a = nums[l].first, b = nums[r].first;
            if (a + b == target && l != i && r != i) {
                cout << nums[i].second << ' ' << nums[l].second << ' ' << nums[r].second << '\n';
                goto end;
            } else if (a + b < target) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
end:
    return 0;
}