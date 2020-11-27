//Tree
//This is a regular tree, in which every node is linked to a parent, except for the root, which doesn't have one.
//It can be seen as a graph with exactly n - 1 edges and n nodes, and with no cycles. 
//We will assume that node 0 is the root.
//We can explore every node from root to leafs in O(n), thanks to the fact that the amount of edges isn't greater than the amount of nodes. 
#include <bits/stdc++.h>

using namespace std;

class Tree {
    private:
        vector<int> parents;
        vector<vector<int>> children;
    public:
        LinkedList() {
            parents.resize(1, 0);
            children.resize(1);
        }

        void insert(int parent) {
            int n = (int)parents.size();
            parents.push_back(parent);
            children[parent].push_back(n);
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
}