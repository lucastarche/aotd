//Subarray Sum Queries
//Problem: Given an array of n numbers, answer q queries of the form "Update the kth position to x", and print the maximum subarray sum after each update
//Solution: We can use a solution similar to yesterday's, but we need to keep track of four values instead: best prefix, best suffix, best subarray sum, and total sum,
//for each range in the Segment Tree.
//After this, we can combine the best prefix of two ranges as max(leftPrefix, leftTotal + rightPrefix), best suffix as max(rightSuffix, rightTotal + leftSuffix),
//total as leftTotal + rightTotal, and best subarray sum as max(leftBest, rightBest, leftSuffix + rightPrefix), since a maximum subarray is either
//entirely contained in one of the halfs, or passes through the middle point, and is composed of a suffix of the left plus a prefix on the right
//Runtime: O(n log n + q log n)
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct Range {
    int left, right;
    long long bestLeft, bestRight;
    long long best;
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
        st[i] = { idx, idx, max(nums[idx], 0LL), max(nums[idx], 0LL), max(nums[idx], 0LL), nums[idx] };
    }
    for (int i = k + n; i <= 2 * k; i++) {
        st[i] = { i - k, i - k, 0, 0 };
    }

    for (int i = k - 1; i > 0; i--) {
        st[i] = {
            st[leftChild(i)].left,
            st[rightChild(i)].right,
            max(st[leftChild(i)].bestLeft, st[leftChild(i)].total + st[rightChild(i)].bestLeft),
            max(st[rightChild(i)].bestRight, st[rightChild(i)].total + st[leftChild(i)].bestRight),
            max(max(st[leftChild(i)].best, st[rightChild(i)].best),
                st[leftChild(i)].bestRight + st[rightChild(i)].bestLeft),
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
    st[idx].best = st[idx].bestLeft = st[idx].bestRight = max(0LL, val);
    idx = parent(idx);
    while (idx > 0) {
        st[idx].total = st[leftChild(idx)].total + st[rightChild(idx)].total;
        st[idx].bestLeft = max(st[leftChild(idx)].bestLeft, st[leftChild(idx)].total + st[rightChild(idx)].bestLeft);
        st[idx].bestRight = max(st[rightChild(idx)].bestRight, st[rightChild(idx)].total + st[leftChild(idx)].bestRight);
        st[idx].best = max(max(st[leftChild(idx)].best, st[rightChild(idx)].best),
            st[leftChild(idx)].bestRight + st[rightChild(idx)].bestLeft);
        idx = parent(idx);
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
        int k, x;
        cin >> k >> x;
        update(st, k, x);
        cout << st[1].best << '\n';
    }
    cout << '\n';
}