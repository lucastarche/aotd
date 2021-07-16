//Flight Discount
//Problem: Given a weighted directed graph, we want to find the minimum path from 1 to n, if we can change the value of a single edge from w to floor(w / 2)
//Solution: We can consider this graph as having twice the number of nodes: the node i represents the minimum distance from 1 to i before changing the value,
//whereas node i + n represents the distance from 1 to i while already having used the discount.
//This works because we can only go from [1, n] to [n + 1, 2n], but not viceversa, so the discount is used at most once
//After forming this graph, we simply run Dijkstra's algorithm to get the shortest path
//Runtime: O(m + n log n)
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        adj[i].push_back({ i + n, 0LL });
    }

    for (int i = 0; i < m; i++) {
        int from, to;
        long long w;
        cin >> from >> to >> w;
        adj[from].push_back({ to, w });
        adj[from].push_back({ to + n, w / 2LL });
        adj[from + n].push_back({ to + n, w });
    }

    vector<long long> dist(2 * n + 1, INF);
    vector<bool> processed(2 * n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1] = 0;
    pq.push({ 0, 1 });
    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        if (processed[curr])
            continue;
        processed[curr] = true;
        for (auto& [a, w] : adj[curr]) {
            if (dist[a] > dist[curr] + w) {
                dist[a] = dist[curr] + w;
                pq.push({ dist[a], a });
            }
        }
    }

    cout << dist[2 * n] << '\n';
}