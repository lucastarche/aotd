//DFS Tree Diameter
//It turns out that we don't need all the mess from yesterday to get the diameter: we can simply run two DFS to get it.
//The main idea is to first run a DFS from any node, to get the one which is furthest away. Then, we run another DFS from the furthest node.
//The answer will be the distance between the nodes that we found in the first and second Depth First Searches.
//I won't prove why this happens, but it should be intuitive as to why.
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

    void dfs(int start, int& furthest, int& ans) {
        vector<bool> visit(n, false);
        vector<int> dist(n, 0);
        stack<int> next;
        int count = 0;

        next.push(start);
        while (!next.empty()) {
            int curr = next.top();
            next.pop();
            if (visit[curr])
                continue;
            visit[curr] = true;
            if (!visit[parents[curr]]) {
                dist[parents[curr]] = dist[curr] + 1;
                next.push(parents[curr]);
            }
            for (auto node : children[curr]) {
                if (!visit[node]) {
                    dist[node] = dist[curr] + 1;
                    next.push(node);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] > ans) {
                ans = dist[i];
                furthest = i;
            }
        }
    }

    int DFSTreeDiameter() {
        int ans = 0, furthest;

        dfs(0, furthest, ans);
        dfs(furthest, furthest, ans);

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

    cout << tree.DFSTreeDiameter() << '\n';
}