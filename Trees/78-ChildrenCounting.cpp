//Children Counting
//In a tree, we can propagate the request to count the amount of children, given that this has a recursive property.
//Each node is visited once, so it runs in linear time.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

class Tree {
    private:
        int n;
        vector<int> parents;
        vector<vector<int>> children;
    public:
        Tree() {
            parents.resize(1, 0);
            children.resize(1);
            n = 1;
        }

        void insert(int parent) {
            parents.push_back(parent);
            children[parent].push_back(n);
            n++;
        }

        int countChildren(int start) {
            if (start >= n) return -1;
            int ans = 0;
            for (auto child : children[start]) {
                ans += countChildren(child) + 1;
            }
            return ans;
        }
};

int main() {
    int amount;
    cin >> amount;
    Tree tree;
    for (int i = 0; i < amount; i++) {
        int temp;
        cin >> temp;
        tree.insert(temp);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        cout << tree.countChildren(query) << '\n';
    }
}