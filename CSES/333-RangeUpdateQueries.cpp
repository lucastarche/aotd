//Range Update Queries
//Problem: Given an array of n numbers, answer q of the following queries:
//1. Give the number in the kth position
//2. Add x to each number in the range [a, b]
//Solution: We can use a Segment Tree over a difference array to be able to answer both queries efficiently.
//A difference array maintains the value of v[i] - v[i - 1], that is, the change from one element to the next
//Note that the sum of all elements in the difference array from 1 to i yields the value of i
//Also note that if we increase a and a+1 by x, their difference stays the same
//We can use all of this to only update two indices per query 2: we add x to the ath position, and we subtract x from the (b + 1)th position
//As for the queries 1, we simply return sum(1, k)
//Runtime: O(n log n + q log n)
#include <bits/stdc++.h>

using namespace std;

struct Range {
    int left, right;
    long long value;
};

inline int leftChild(int n) { return 2 * n; }
inline int rightChild(int n) { return 2 * n + 1; }
inline int parent(int n) { return n / 2; }

int nextPot2(int n) {
    int ans = 1;
    while (ans < n) {
        ans *= 2;
    }
    return ans;
}

vector<Range> build(const vector<long long>& nums) {
    int n = (int)nums.size() - 1, k = nextPot2(n);
    vector<Range> st(2 * k + 1);
    for (int i = k; i < k + n; i++) {
        st[i] = { i - k + 1, i - k + 1, nums[i - k + 1] };
    }
    for (int i = k + n; i <= 2 * k; i++) {
        st[i] = { i - k, i - k, 0 };
    }

    for (int i = k - 1; i > 0; i--) {
        st[i] = { st[leftChild(i)].left, st[rightChild(i)].right, st[leftChild(i)].value + st[rightChild(i)].value };
    }

    st[0].value = k;
    return st;
}

void update(vector<Range>& st, int idx, long long val) {
    int n = st[0].value;
    idx += n - 1;
    st[idx].value += val;
    idx = parent(idx);
    while (idx > 0) {
        st[idx].value = st[leftChild(idx)].value + st[rightChild(idx)].value;
        idx = parent(idx);
    }
}

long long query(const vector<Range>& st, int left, int right, int curr) {
    if (st[curr].right < left || st[curr].left > right)
        return 0;
    else if (left <= st[curr].left && st[curr].right <= right)
        return st[curr].value;
    return query(st, left, right, leftChild(curr)) + query(st, left, right, rightChild(curr));
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> nums(n + 1), diff(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        diff[i] = nums[i] - nums[i - 1];
    }
    diff[n + 1] = 0 - nums[n];

    vector<Range> st = build(diff);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int from, to, val;
            cin >> from >> to >> val;
            update(st, from, val);
            update(st, to + 1, -val);
        } else {
            int idx;
            cin >> idx;
            cout << query(st, 1, idx, 1) << '\n';
        }
    }
}