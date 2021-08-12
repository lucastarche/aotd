//Hotel Queries
//Problem: Given n hotels, each with k_i available rooms, we have q groups of people in a queue, and we want to give them room in the leftmost hotel with at least x_j rooms
//After giving the group the rooms, these are now occupied, so the ith hotel now has (k_i - x_j) available rooms. Simulate the process
//Solution: We can use a maximum value segment tree to keep track of the greatest value in [a..b]
//When we want to make a query, we check for the left and right children. If the left is greater than x_i, we recurse through the left branch, else through the right branch
//Once we reach a leaf, we decrease the amount in the leaf, and return
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
        st[i] = { i - k, i - k, -INF };
    }

    for (int i = k - 1; i > 0; i--) {
        st[i] = { st[leftChild(i)].left, st[rightChild(i)].right, max(st[leftChild(i)].value, st[rightChild(i)].value) };
    }

    st[0].value = k;
    return st;
}

void update(vector<Range>& st, int idx, int val) {
    int n = st[0].value;
    idx += n - 1;
    st[idx].value += val;
    idx = parent(idx);
    while (idx > 0) {
        st[idx].value = max(st[leftChild(idx)].value, st[rightChild(idx)].value);
        idx = parent(idx);
    }
}

int query(vector<Range>& st, int amount, int curr) {
    if (st[curr].value < amount) {
        return 0;
    } else if (st[curr].left == st[curr].right) {
        update(st, st[curr].left, -amount);
        return st[curr].left;
    } else if (st[leftChild(curr)].value >= amount) {
        return query(st, amount, leftChild(curr));
    } else {
        return query(st, amount, rightChild(curr));
    }
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
        cout << query(st, t, 1) << ' ';
    }
    cout << '\n';
}