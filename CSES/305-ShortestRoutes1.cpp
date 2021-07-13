//Shortest Routes 1
//Problem: Given a list of n cities, and m unidirectional flights from a to b, with cost c, find the shortest route from 1 to every other city.
//It is guaranteed there is always at least one path from 1 to every other city.
//Solution: We represent it as a graph, and then use Dijkstra's algorithm to find the shortest paths.
//Note that we either need to use a priority queue ordered from smaller to bigger, or use the * -1 trick (or make your own priority queue)
//We also need to keep an array of already processed nodes, in order to make the solution fit in time
//Runtime: O(m + n log n)
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

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

    vector<long long> dist(n + 1, INF);
    vector<bool> processed(n + 1, false);
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, 1 });
    while (!pq.empty()) {
        auto curr = pq.top().second;
        pq.pop();
        if (processed[curr])
            continue;
        processed[curr] = true;
        for (auto [a, w] : adj[curr]) {
            if (dist[a] > dist[curr] + w) {
                dist[a] = dist[curr] + w;
                pq.push({ dist[a], a });
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << '\n';
}