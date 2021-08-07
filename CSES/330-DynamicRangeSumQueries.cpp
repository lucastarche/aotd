//Dynamic Range Sum Queries
//Problem: Given an array of n numbers, answer q queries of the form "What is the sum in the range [l, r]" or "Update the value in the ith position to be equal to k"
//Solution: We can use a Fenwick Tree or Binary Indexed Tree to answer both of this queries.
//We have to keep track of which values are stored in the actual array, so when we update we do so with a delta of k - nums[i]
//To answer the sum queries, we get the sum in range [1, r] and [1, l - 1] and give the difference of the two
//Runtime: O(n log n + q log n)
#include <bits/stdc++.h>

using namespace std;

inline int lsOne(int n) {
    return n & (-n);
}

void adjust(vector<long long>& fenwick, int idx, long long delta) {
    int n = (int)fenwick.size();
    while (idx < n) {
        fenwick[idx] += delta;
        idx += lsOne(idx);
    }
}

long long sum(vector<long long>& fenwick, int idx) {
    long long ans = 0;
    while (idx >= 1) {
        ans += fenwick[idx];
        idx -= lsOne(idx);
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> nums(n + 1), fenwick(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        adjust(fenwick, i, nums[i]);
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx;
            long long k;
            cin >> idx >> k;
            adjust(fenwick, idx, k - nums[idx]);
            nums[idx] = k;
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum(fenwick, r) - sum(fenwick, l - 1) << '\n';
        }
    }
}