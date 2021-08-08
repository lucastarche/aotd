//Dynamic Range Minimum Queries
//Problem: Given an array of n numbers, answer q queries of the form "What is the minimum number in the range [l, r]" or "Update the value in the ith position to be equal to k"
//Solution: We can use a Segment Tree to answer both of this queries.
//This idea consists of basically having a tree of ranges, on which each node stores the composition of its two childs
//Since min(a, b) is associative, that is, min(a, min(b, c)) = min(min(a, b), c), the Segment Tree doesn't break and we answer the queries correctly
//Runtime: O(n log n + q log n)
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Range {
    int left, right;
    int value;
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

vector<Range> build(const vector<int>& nums) {
    int n = (int)nums.size() - 1, k = nextPot2(n);
    vector<Range> st(2 * k + 1);
    for (int i = k; i < k + n; i++) {
        st[i] = { i - k + 1, i - k + 1, nums[i - k + 1] };
    }
    for (int i = k + n; i <= 2 * k; i++) {
        st[i] = { i - k, i - k, INF };
    }

    for (int i = k - 1; i > 0; i--) {
        st[i] = { st[leftChild(i)].left, st[rightChild(i)].right, min(st[leftChild(i)].value, st[rightChild(i)].value) };
    }

    st[0].value = k;
    return st;
}

void update(vector<Range>& st, int idx, int val) {
    int n = st[0].value;
    idx += n - 1;
    st[idx].value = val;
    idx = parent(idx);
    while (idx > 0) {
        st[idx].value = min(st[leftChild(idx)].value, st[rightChild(idx)].value);
        idx = parent(idx);
    }
}

int query(const vector<Range>& st, int left, int right, int curr) {
    if (st[curr].right < left || st[curr].left > right)
        return INF;
    else if (left <= st[curr].left && st[curr].right <= right)
        return st[curr].value;
    return min(query(st, left, right, leftChild(curr)), query(st, left, right, rightChild(curr)));
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    vector<Range> st = build(nums);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, val;
            cin >> idx >> val;
            update(st, idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(st, l, r, 1) << '\n';
        }
    }
}