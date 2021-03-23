//Longest Rooted Path
//This determines the longest path we can get in the rooted subtree with root n. This will be useful later on when we want to get the tree's diameter.
//We can use recursion again, thanks to the fact that the longest path of node n will be the max of each child, plus one.
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
        children.push_back({});
        children[parent].push_back(n);
        n++;
    }

    int RootedLongestPath(int start) {
        int ans = 0;
        for (auto child : children[start]) {
            ans = max(ans, RootedLongestPath(child) + 1);
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
        cout << tree.RootedLongestPath(query) << '\n';
    }
}