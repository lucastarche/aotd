//Planets and Kingdoms
//Problem: Given a directed graph, find all the Strongly Connected Components, and report to which component each node belongs
//Solution: We can just reuse the solution for yesterday, but slightly modifying the output.
//Note that Kosaraju's implementation remains the same
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& adj, vector<bool>& visit, vector<int>& order, int curr) {
    if (visit[curr])
        return;
    visit[curr] = true;
    for (auto a : adj[curr]) {
        dfs(adj, visit, order, a);
    }
    order.push_back(curr);
}

void dfs2(const vector<vector<int>>& adj, vector<int>& component, int curr, int k) {
    if (component[curr])
        return;
    component[curr] = k;
    for (auto a : adj[curr]) {
        dfs2(adj, component, a, k);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), rev(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        rev[to].push_back(from);
    }

    vector<int> order;
    vector<bool> visit(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (visit[i])
            continue;
        dfs(adj, visit, order, i);
    }

    vector<int> component(n + 1);
    reverse(order.begin(), order.end());

    int k = 0;
    for (auto a : order) {
        if (component[a])
            continue;
        k++;
        dfs2(rev, component, a, k);
    }

    cout << k << '\n';
    for (int i = 1; i <= n; i++)
        cout << component[i] << ' ';
    cout << '\n';
}