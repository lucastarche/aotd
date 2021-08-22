//Company Queries 2
//Problem: Given a rooted tree, find the Lowest Common Ancestor of q pairs of nodes
//Solution: We can use binary lifting yet again:
//We start by getting both nodes to be at the same depth from the root, which can be done with yesterday's algorithm.
//After this, we can get the LCA by increasing both nodes by the same height if said parent is different, or storing it
//and keep trying to increase if it is the same
//Runtime: O(n log n + q log n)
#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& adj, vector<int>& depth, int curr) {
    for (auto a : adj[curr]) {
        depth[a] = depth[curr] + 1;
        dfs(adj, depth, a);
    }
}

int query(const vector<vector<int>>& parent, const vector<int>& depth, int a, int b) {
    const int size = (int)parent[0].size();
    if (depth[a] < depth[b])
        swap(a, b);

    //Get a and b to be at the same depth
    int delta = depth[a] - depth[b];
    for (int i = 0; i < size; i++) {
        if (delta & (1 << i)) {
            a = parent[a][i];
        }
    }

    int lastParent = -1;
    for (int i = size - 1; i >= 0; i--) {
        if (parent[a][i] == parent[b][i]) {
            //If the (2^i)th parents are the same, take note of that
            lastParent = parent[a][i];
        } else {
            //Else, make both a and b equal to their (2^i)th parent
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    if (a == b)
        return a;
    else
        return lastParent;
}

int main() {
    int n, q;
    cin >> n >> q;
    const int size = floor(log2(n)) + 1;

    vector<vector<int>> parent(n + 1, vector<int>(size, 0));
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> parent[i][0];
        adj[parent[i][0]].push_back(i);
    }

    vector<int> depth(n + 1, 0);
    dfs(adj, depth, 1);

    for (int j = 1; j < size; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(parent, depth, a, b) << '\n';
    }
}