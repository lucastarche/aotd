//Subarray Distinct Values
//Problem: Given an array of length k, count the number of different subarrays which have at most k values
//Solutions: We can see the largest subarray we can form starting at i which have at most k values.
//Then we can add to the answer the difference between the start and end, since if the array [a, b] has at most k values, so does [a, b - 1]
//We can efficiently keep track of which elements are in the subarray by using a map (or hashmap for a better complexity)
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    map<int, long long> amount;
    long long left = 0, right = 0, ctr = 0, ans = 0;
    while (left < n) {
        while (right < n && ctr <= k) {
            if (amount[nums[right]] == 0)
                ctr++;
            if (ctr > k) {
                ctr--;
                break;
            }
            amount[nums[right]]++;
            right++;
        }

        ans += right - left;
        if (amount[nums[left]] == 1)
            ctr--;
        amount[nums[left]]--;
        left++;
    }

    cout << ans << '\n';
}