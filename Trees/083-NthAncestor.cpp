//Nth Ancestor
//This is a waay faster method, which uses two important concepts in Computer Science: preprocessing and Binary Lifting.
//Binary lifting refers to segmenting a problem in such a way that we can add results we already know to get new ones.
//In this case, we preprocess Nth Ancestor for each node with every power of two lower than N, which allows us to add those results up.
//Runtime: O(log n) after O(n log n) preprocessing.
//Note: this version is in a static tree, but it isn't hard to support dynamic trees as well. The main corner case is when the table needs to support one more power of 2.
#include <bits/stdc++.h>

using namespace std;

class Tree {
private:
    int n;
    vector<int> parents;
    vector<vector<int>> children;
    vector<vector<int>> ancestors;

public:
    Tree(vector<int> parents)
        : parents { parents } {
        int n = (int)parents.size();
        children.resize(n);
        ancestors.resize(n);
        for (int i = 0; i < n; i++) {
            children[parents[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            ancestors[i].push_back(parents[i]);
        }

        int val = 2, exponent = 1;
        while (val <= n) {
            for (int i = 0; i < n; i++) {
                int lastAncestor = ancestors[i][exponent - 1];
                int newAncestor = ancestors[lastAncestor][exponent - 1];
                ancestors[i].push_back(newAncestor);
            }

            val *= 2;
            exponent++;
        }
    }

    int NthAncestor(int node, int x) {
        if (x > n)
            return 0;
        if (node == 0)
            return 0;
        if (x == 0)
            return node;

        int curr = node, val = 1, exponent = 0;
        while (val <= n) {
            if (x & val) {
                curr = ancestors[curr][exponent];
            }

            val *= 2;
            exponent++;
        }
        return curr;
    }
};

int main() {
    int amount;
    cin >> amount;
    vector<int> parents = { 0 };
    for (int i = 0; i < amount; i++) {
        int temp;
        cin >> temp;
        parents.push_back(temp);
    }

    Tree tree(parents);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int node, n;
        cin >> node >> n;
        cout << tree.NthAncestor(node, n) << '\n';
    }
}