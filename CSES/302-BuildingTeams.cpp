//Building Teams
//Problem: Given a group of n students, and m friendships between two students, we want to form two teams in such a way that no team has a pair of friends
//Solution: We can represent the relationships as a graph, with students as nodes, and friendships as edges
//Then, we can try doing a bicolouring of the graph, which can easily be checked with a BFS on each component
//Note that if there is a cycle of odd length, for example three, then we cant form the teams, since two out of the three friends will be in the same team
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

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

    queue<int> q;
    vector<int> color(n + 1, 0);

    bool bipartite = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] != 0)
            continue;
        color[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == 0) {
                    color[v] = (color[u] == 1) ? 2 : 1;
                    q.push(v);
                } else if (color[u] == color[v]) {
                    bipartite = false;
                }
            }
        }
    }

    if (bipartite) {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}