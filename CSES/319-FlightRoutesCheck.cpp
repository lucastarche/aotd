//Flight Routes Check
//Problem: Given a directed graph, determine if we can go from every node a to every node b, or report a case where it is not possible
//Solution: This is a problem which can be solved using Strongly Connected Components (SCCs)
//The idea is that if the graph has a single SCC, it is possible, else there is at least one case where this is not possible, by definition
//For this, we can run Kosaraju's algorithm, which consists of two DFSs. The first one is ran over the regular graph, and we order nodes by their exit times
//After this, we reverse the order and run a DFS over the inverted graph, which has an edge j->i if the original graph had the edge i->j
//In this DFS we start by the nodes we gave in the reversed order, and assign all the nodes visited from the start to the same component
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
    pair<int, int> ans;
    for (auto a : order) {
        if (component[a])
            continue;
        k++;
        dfs2(rev, component, a, k);
        if (k == 1) {
            ans.second = a;
        } else if (k == 2) {
            ans.first = a;
        }
    }

    if (k > 1) {
        cout << "NO\n"
             << ans.first << ' ' << ans.second << '\n';
    } else {
        cout << "YES\n";
    }
}