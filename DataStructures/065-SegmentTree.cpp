//Segment Tree
//This is another data structure similar to the Fenwick Tree, but that supports a more wide range of operations.
//The idea is to split the array in different power of two length ranges, so that we can then decompose each query into a sum of this ranges.
//The Segment Tree is an special case of a Binary Tree, and in this case we use an array double the original size, so we can get both children in O(1), without using pointers.
//Runtime: Building the segment tree takes O(n).
//Each update query and range query then takes O(log n).
#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int l;
    int r;
    int val;
} TreeRange;

class SegmentTree {
private:
    const int IDENTITY = 0;
    int n;
    vector<TreeRange> st;

    static int nextPot(int n) {
        int ans = 1;
        while (ans < n)
            ans *= 2;
        return ans;
    }

    static inline int leftChild(int n) {
        return 2 * n;
    }

    static inline int rightChild(int n) {
        return 2 * n + 1;
    }

    static inline int parent(int n) {
        return n / 2;
    }

public:
    SegmentTree(vector<int> arr) {
        n = (int)arr.size();
        n = nextPot(n);

        st.resize(2 * n);
        arr.resize(n, IDENTITY);

        for (int i = n; i < 2 * n; i++) {
            st[i] = { arr[i - n], i, i };
        }

        for (int i = n - 1; i >= 1; i--) {
            st[i] = {
                st[leftChild(i)].val + st[rightChild(i)].val,
                st[leftChild(i)].l,
                st[rightChild(i)].r
            };
        }
    }

    int query(int l, int r) {
        return query(1, l + n - 1, r + n - 1);
    }

    void update(int pos, int val) {
        st[pos].val = val;
        while (pos > 0) {
            pos = parent(pos);
            st[pos].val = st[leftChild(pos)].val + st[rightChild(pos)].val;
        }
    }

private:
    int query(int pos, int l, int r) {
        if (st[pos].r < l || st[pos].l > r)
            return IDENTITY;
        else if (l <= st[pos].l && r >= st[pos].r)
            return st[pos].val;

        int leftQuery = query(leftChild(pos), l, r);
        int rightQuery = query(rightChild(pos), l, r);
        return leftQuery + rightQuery;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree st(arr);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 'U') {
            int pos, val;
            cin >> pos >> val;
            st.update(pos, val);
        } else if (type == 'Q') {
            int l, r;
            cout << st.query(l, r) << '\n';
        }
    }
}
