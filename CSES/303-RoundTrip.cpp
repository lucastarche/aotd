//Round Trip
//Problem: Given a map with n cities and m roads, we want to find a route such that we start and end in the same city, and visit every other city at most once.
//Solution: We want to represent the map as a graph, and find a cycle in it with length greater than one (since we have to visit at most two cities)
//We can use a DFS, since we know a cycle exists if and only if we can reach a city we have already visited in a way other than from its parent.
//With the array ans we pass it around until we find a cycle, at which point we insert the current node, and build it backwards.
//Note that we need to check if the front and back are different, because otherwise we have already done the full cycle, and we would be adding cities that dont belong to it.
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans, int u, int parent) {
    if (visited[u]) {
        ans = { u };
        return;
    }
    visited[u] = true;

    for (auto a : adj[u]) {
        if (a == parent)
            continue;
        dfs(adj, visited, ans, a, u);
        if (ans.empty())
            continue;
        if ((int)ans.size() == 1 || ans.front() != ans.back()) {
            ans.push_back(u);
        }
        return;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    vector<bool> visited(n + 1, false);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        dfs(adj, visited, ans, i, -1);
        if (ans.size())
            break;
    }

    if (ans.size()) {
        cout << (int)ans.size() << '\n';
        for (auto a : ans)
            cout << a << ' ';
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}