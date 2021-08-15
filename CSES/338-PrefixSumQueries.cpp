//Prefix Sum Queries
//Problem: Given an array of n numbers, answer q queries of the form "Update the kth element to x" or "Give the maximum prefix sum in [a, b]"
//Solution: We will use a Segment Tree to keep track of two values per range: the total sum in [a, b] and the maximum prefix sum in [a, b]
//The first value is trivial to compose from the two children, since its just the sum of the two
//The second value, on the other hand, requires us to take the max between the maximum prefix sum on the left, or the total on the left plus the maximum prefix sum on the right
//After this, we simply compose each query by forming the appropriate ranges
//Runtime: O(n log n + q log n)
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct Range {
    int left, right;
    long long prefix;
    long long total;
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

vector<Range> build(vector<long long>& nums) {
    int n = (int)nums.size() - 1, k = nextPot2(n);
    vector<Range> st(2 * k + 1);
    for (int i = k; i < k + n; i++) {
        int idx = i - k + 1;
        st[i] = { idx, idx, max(nums[idx], 0LL), nums[idx] };
    }
    for (int i = k + n; i <= 2 * k; i++) {
        st[i] = { i - k, i - k, 0, 0 };
    }

    for (int i = k - 1; i > 0; i--) {
        st[i] = {
            st[leftChild(i)].left,
            st[rightChild(i)].right,
            max(max(st[leftChild(i)].prefix, st[leftChild(i)].total + st[rightChild(i)].prefix), 0LL),
            st[leftChild(i)].total + st[rightChild(i)].total
        };
    }

    st[0].total = k;
    return st;
}

void update(vector<Range>& st, int idx, long long val) {
    int n = st[0].total;
    idx += n - 1;
    st[idx].total = val;
    st[idx].prefix = val;
    idx = parent(idx);
    while (idx > 0) {
        st[idx].total = st[leftChild(idx)].total + st[rightChild(idx)].total;
        st[idx].prefix = max(max(st[leftChild(idx)].prefix,
                                 st[leftChild(idx)].total + st[rightChild(idx)].prefix),
            0LL);
        idx = parent(idx);
    }
}

pair<long long, long long> query(vector<Range>& st, int left, int right, int curr) {
    if (st[curr].right < left || st[curr].left > right) {
        return { 0, 0 };
    } else if (left <= st[curr].left && st[curr].right <= right) {
        return { st[curr].prefix, st[curr].total };
    } else {
        auto lhs = query(st, left, right, leftChild(curr)),
             rhs = query(st, left, right, rightChild(curr));
        return {
            max(max(lhs.first, lhs.second + rhs.first), 0LL),
            lhs.second + rhs.second
        };
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    vector<Range> st = build(nums);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            update(st, k, u);
            nums[k] = u;
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(st, a, b, 1).first << '\n';
        }
    }
    cout << '\n';
}