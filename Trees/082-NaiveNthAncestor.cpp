//Naive Nth Ancestor
//Gets the nth ancestor of a given node by iterating until we find it or get to the root.
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

    int NthAncestor(int node, int n) {
        if (node == 0)
            return 0; //The root is its own ancestor
        return NthAncestor(parents[node], n - 1);
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
        int node, n;
        cin >> node >> n;
        cout << tree.NthAncestor(node, n) << '\n';
    }
}