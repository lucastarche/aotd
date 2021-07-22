//Game Routes
//Problem: Given a DAG, find the number of paths from 1 to n modulo 1e9 + 7
//Solution: This is another problem of DP in DAG, so we first start by toposorting the graph
//After this, the number of ways to get to node j is the sum of the ways we can get to every node i such that i -> j is an edge
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

void dfs(const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& toposort, int curr) {
    visited[curr] = true;
    for (auto a : adj[curr]) {
        if (!visited[a])
            dfs(adj, visited, toposort, a);
    }
    toposort.push_back(curr);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    vector<int> toposort;
    vector<bool> visited(n + 1);
    dfs(adj, visited, toposort, 1);
    reverse(toposort.begin(), toposort.end());

    vector<long long> ways(n + 1);
    ways[1] = 1;
    for (auto a : toposort) {
        for (auto i : adj[a])
            ways[i] = (ways[i] + ways[a]) % MOD;
    }

    cout << ways[n] << '\n';
}