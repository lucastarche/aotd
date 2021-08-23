//Distance Queries
//Problem: Given a tree, find the distance between q pairs of nodes (a, b)
//Solution: We can root the tree to 1, and see that the distance between a and b is always equal to
//(depth[a] - depth[LCA(a, b)]) + (depth[b] - depth[LCA(a, b)]), so we can simply reuse yesterday's algorithm to get the LCA.
//This works because we can see the length as the path a~LCA(a, b)~b, and the distance between a and LCA(a, b) is depth[a] - depth[LCA(a, b)] (same for b)
//Then we simply get the LCA and print the result which the formula gives us
//Runtime: O(n log n + q log n)
#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& ady, vector<vector<int>>& parent, vector<int>& depth, int curr, int from) {
    for (auto a : ady[curr]) {
        if (a == from)
            continue;
        parent[a][0] = curr;
        depth[a] = depth[curr] + 1;
        dfs(ady, parent, depth, a, curr);
    }
}

int LCA(const vector<vector<int>>& parent, const vector<int>& depth, int a, int b) {
    const int size = (int)parent[0].size();
    if (depth[a] < depth[b])
        swap(a, b);

    int delta = depth[a] - depth[b];
    for (int i = 0; i < size; i++) {
        if (delta & (1 << i)) {
            a = parent[a][i];
        }
    }

    if (a == b)
        return a;

    int lastParent = 1;
    for (int i = size - 1; i >= 0; i--) {
        if (parent[a][i] == parent[b][i]) {
            lastParent = parent[a][i];
        } else {
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
    scanf("%d %d", &n, &q);
    const int size = floor(log2(n)) + 1;

    vector<vector<int>> parent(n + 1, vector<int>(size, 0));
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    parent[1][0] = 1;
    vector<int> depth(n + 1, 0);
    dfs(adj, parent, depth, 1, -1);

    for (int j = 1; j < size; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    queue<int> q_ans;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int k = LCA(parent, depth, a, b);
        int ans = depth[a] + depth[b] - 2 * depth[k];
        q_ans.push(ans);
    }

    while (!q_ans.empty()) {
        printf("%d\n", q_ans.front());
        q_ans.pop();
    }
}