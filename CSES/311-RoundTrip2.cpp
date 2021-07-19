//Round Trip 2
//Problem: Given a directed graph, find a cycle in it and print it, or report that there is none
//Solution: We can modify our solution to Round Trip 1, but making edges directed, and having three states for a node instead of two
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

bool dfs(const vector<vector<int>>& adj, vector<int>& visit, vector<int>& ans, int curr) {
    if (visit[curr] == 2) {
        return false;
    } else if (visit[curr] == 1) {
        ans = { curr };
        return true;
    }
    visit[curr] = 1;

    for (auto a : adj[curr]) {
        if (dfs(adj, visit, ans, a)) {
            if (ans.size() == 1 || ans.front() != ans.back())
                ans.push_back(curr);
            return true;
        }
    }

    visit[curr] = 2;
    return false;
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

    vector<int> ans, visit(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (visit[i])
            continue;
        if (dfs(adj, visit, ans, i)) {
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            for (auto a : ans)
                cout << a << ' ';
            cout << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
}