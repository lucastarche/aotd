//List Removals
//Problem: Given a list of n numbers, remove the element in the given possition, and print its value
//Solution: We can use a segment tree with the sum of elements we haven't removed yet from the list.
//When we want to remove an element, we see if the index is greater than the amount of elements in the left child
//If so, we recurse in the right with idx - amount[left], else we recurse on the left with idx
//Finally, when we reach a leaf, we return the index in the position, and update the position to remove it
//Runtime: O(n log n)
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

vector<Range> build(int n) {
    int k = nextPot2(n);
    vector<Range> st(2 * k + 1);
    for (int i = k; i < k + n; i++) {
        st[i] = { i - k + 1, i - k + 1, 1 };
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

void update(vector<Range>& st, int idx) {
    int n = st[0].value;
    idx += n - 1;
    st[idx].value--;
    idx = parent(idx);
    while (idx > 0) {
        st[idx].value = st[leftChild(idx)].value + st[rightChild(idx)].value;
        idx = parent(idx);
    }
}

int query(vector<Range>& st, int amount, int curr) {
    if (st[curr].left == st[curr].right) {
        update(st, st[curr].left);
        return st[curr].left;
    } else if (st[leftChild(curr)].value > amount) {
        return query(st, amount, leftChild(curr));
    } else {
        return query(st, amount - st[leftChild(curr)].value, rightChild(curr));
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    vector<Range> st = build(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cout << nums[query(st, t - 1, 1)] << ' ';
    }
    cout << '\n';
}