//Subarray Sums 2
//Problem: Given an array of n integers, find the number of subarrays that yield sum x
//Solution: We can't use yesterday's idea because we can have negative numbers as well, which breaks our two pointers idea.
//We can, however, maintain a set with the number of ways we can form a sum k with the first k_i integers.
//Then, we add on each step the number of ways we can form (prefixSum - x) so far, where prefixSum is the sum of the numbers from 0 to i
//Runtime: O(n log n) (can be O(n) via hashing)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    map<long long, long long> sums;
    long long prefixSum = 0LL, ans = 0LL;
    for (int i = 0; i < n; i++) {
        prefixSum += nums[i];
        ans += sums[prefixSum - x];
        sums[prefixSum]++;
    }

    cout << ans << '\n';
}