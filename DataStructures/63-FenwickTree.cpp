//Fenwick Tree (also known as Binary Indexed Tree)
//This is a dynamic variant of the prefix sum array. It can be used to get the subarray sum efficiently, while also being able to change the values in the array.
//There is a more powerful data structure, which supports other operations, known as a Segment Tree.
//Note: The Fenwick Tree asumes the array is 1-indexed.
//Note 2: By dynamic we mean that one can change the value at one index, but the size of the array remains constant.
//Runtime: we can build the tree in O(n log n), get a subarray sum in O(log n), and replace a value in the array in O(log n).
#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
    private:
        vector<int> tree;
    public:
        FenwickTree(const vector<int> &arr) {
            int N = (int)arr.size();
            tree.resize(N + 1, 0);
            for (int i = 1; i <= N; i++) {
                replace(i, arr[i]);
            }
        }

        int LeastSignificantOne(int index) {
            return index & -index;
        }

        void replace(int index, int val) {
            int delta = val - tree[index];
            while (index <= tree.size()) {
                tree[index] += delta;
                index += LeastSignificantOne(index);
            }
        }

        //Gets the subarray sum in the range [1, index]
        int sum(int index) {
            int ans = 0;
            while (index >= 1) {
                ans += tree[index];
                index -= LeastSignificantOne(index);
            }
            return ans;
        }

        int sum(int from, int to) {
            return sum(to) - sum(from - 1);
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    FenwickTree FT = FenwickTree(arr);

    int q;
    cin >> q;
    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        if (type == 'U') {
            int index, val;
            cin >> index >> val;
            FT.replace(index, val);
        }
        else if (type == 'Q') {
            int from, to;
            cin >> from >> to;
            cout << FT.sum(from, to) << '\n';
        }
    }
}
