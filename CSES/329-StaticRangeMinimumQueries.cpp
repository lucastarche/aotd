//Static Range Minimum Queries
//Problem: Given an array of n numbers, answer q queries of the form "What is the minimum in range [a, b]?"
//Solution: We can use a Sparse Table to reconstruct the answer. The idea is that if we know for every power of 2 the solution to [a, a + 2^k],
//we can get the minimum by using the ranges [l, 2^k] and [r - 2^k + 1, 2^k], where k = log2(r - l + 1), and doing the minimum of these two.
//We can build the table in O(n log n), since the maximum value of k such that 2^k < n is k < log2(n).
//Runtime: O(n log n + q), since we can answer the queries in constant time
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n, q;
    cin >> n >> q;
    int maxPow = ceil(log2(n)) + 1;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> table(n, vector<int>(maxPow, INF));
    for (int i = 0; i < n; i++) {
        table[i][0] = nums[i];
    }

    for (int j = 1; j < maxPow; j++) {
        for (int i = 0; i < n; i++) {
            table[i][j] = table[i][j - 1];
            if (i + (1 << (j - 1)) < n)
                table[i][j] = min(table[i][j], table[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int j = log2(r - l + 1);
        cout << min(table[l][j], table[r - (1 << j) + 1][j]) << '\n';
    }
}