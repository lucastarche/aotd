//Static Range Sum Queries
//Problem: Given an array of n numbers, respond to q queries of the form "What is the sum in the range [l, r]?"
//Solution: We can use a Prefix Sum Array, which stores in the ith position the sum in [1, i]
//This can be calculated in O(n), since we iterate through the array only once.
//After this, we can respond to each query by doing prefix[r] - prefix[l - 1], since this is the difference of the ranges [1, l - 1] and [1, r], which yields [l, r]
//Runtime: O(n + q)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> prefixSum(n + 1);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << prefixSum[r] - prefixSum[l - 1] << '\n';
    }
}