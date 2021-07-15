//High Score
//Problem: Given a directed weighted graph, find the longest path from 1 to n, or -1 if it can grow infinitely
//Assume there is always a path from 1 to n
//Solution: First we will run n - 1 iterations of Bellman-Ford to find the longest path from 1 to every other node.
//Then we will run a DFS starting from 1 to get all reachable nodes from 1.
//After this, we run one more iteration of Bellman-Ford, and we mark all visited nodes which can grow infinitely.
//Finally, we reverse all the edges in the graph and run DFS again, but starting from n instead
//If we can reach a marked node, it is possible to get an infinitely long path, else we output the distance
//Runtime: O(n * m)
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int from, to;
    long long w;
};

bool dfs(int curr, const vector<vector<int>>& adj, const vector<bool>& marked, vector<bool>& visit) {
    if (visit[curr])
        return false;
    if (marked[curr])
        return true;

    visit[curr] = true;
    for (auto a : adj[curr]) {
        if (dfs(a, adj, marked, visit))
            return true;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].w;
        adj[edges[i].from].push_back(edges[i].to);
    }

    vector<long long> dist(n + 1, -INF);
    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            dist[e.to] = max(dist[e.to], dist[e.from] + e.w);
        }
    }

    vector<bool> visit(n + 1, false);
    vector<bool> marked(n + 1, false);
    dfs(1, adj, marked, visit);

    for (auto e : edges) {
        if (dist[e.to] < dist[e.from] + e.w) {
            marked[e.to] = visit[e.to];
        }
    }

    for (auto& a : adj)
        a.clear();

    for (auto e : edges)
        adj[e.to].push_back(e.from);

    visit = vector<bool>(n + 1, false);
    if (dfs(n, adj, marked, visit)) {
        cout << "-1\n";
    } else {
        cout << dist[n] << '\n';
    }
}