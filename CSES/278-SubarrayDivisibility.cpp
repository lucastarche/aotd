//Subarray Divisibility
//Problem: Given an array of length n, find the number of subarrays which are divisible by n
//Solution: We can count the number of ways we can form a sum equal to k modulo n with a prefix subarray.
//Then the answer is the sum of the ways we can form the current sum with a prefix, so for instance in [3, 1, 2, 7, 4]
//we have 3 + 1 + 2 + 7 = 13, 13 % 5 = 3, and there is one prefix that yields sum 3, the subarray [0, 1), so the answer is 1
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long prefix = 0, ans = 0;
    vector<long long> sums(n);
    sums[0] = 1;

    for (int i = 0; i < n; i++) {
        prefix += nums[i];
        prefix = (prefix % n + n) % n;
        ans += sums[prefix];
        sums[prefix]++;
    }

    cout << ans << '\n';
}