//Investigation
//Problem: Given a weighted directed graph, find the shortest distance from 1 to n, how many paths from 1 to n have this property modulo 1e9 + 7,
//the minimum number of edges a shortest path can have, and the maximum number of edges a shortest path can have
//Solution: Despite asking for multiple things, these can all be done in the same Dijkstra execution.
//The idea is that we keep track of all four properties, and we update them as it corresponds when we find a shorter path, or one of equal lenght
//Runtime: O(m + n log n)
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const long long MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        long long w;
        cin >> from >> to >> w;
        adj[from].push_back({ to, w });
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, 1 });

    vector<bool> visit(n + 1, false);
    vector<long long> dist(n + 1, INF), ways(n + 1, 0), minFlights(n + 1, INF), maxFlights(n + 1, 0);
    dist[1] = 0;
    ways[1] = 1;
    minFlights[1] = 0;
    maxFlights[1] = 0;

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        if (visit[curr])
            continue;
        visit[curr] = true;
        for (auto& [a, w] : adj[curr]) {
            if (dist[a] == dist[curr] + w) {
                ways[a] += ways[curr];
                ways[a] %= MOD;
                minFlights[a] = min(minFlights[a], minFlights[curr] + 1);
                maxFlights[a] = max(maxFlights[a], maxFlights[curr] + 1);
            } else if (dist[a] > dist[curr] + w) {
                dist[a] = dist[curr] + w;
                ways[a] = ways[curr];
                minFlights[a] = minFlights[curr] + 1;
                maxFlights[a] = maxFlights[curr] + 1;
                pq.push({ dist[a], a });
            }
        }
    }

    cout << dist[n] << ' ' << ways[n] << ' ' << minFlights[n] << ' ' << maxFlights[n] << '\n';
}