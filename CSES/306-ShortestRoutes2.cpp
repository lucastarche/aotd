//Shortest Routes 2
//Problem: Given an undirected weighted graph with n nodes, and m edges, answer q queries of the form "What is the minimum distance from a to b?"
//Solution: Since the graph never changes, we can precompute all the possible queries beforehand, and then just look at the cache each time.
//This is better than running Dijkstra's algorithm for each query, since n <= 500, while q <= 1e5
//Instead, we can take advantage of the low number of nodes to run Floyd-Warshall's algorithm, and get all the possible distances
//Runtime: O(n^3)
//Note that running Dijkstra n times also solve the problem, but still has a complexity of O(n * (n^2 + n log n)) = O(n^3 + n^2 log n) = O(n^3), since m <= n^2
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int from, to;
        long long w;
        cin >> from >> to >> w;
        dist[from][to] = min(dist[from][to], w);
        dist[to][from] = min(dist[to][from], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int from, to;
        cin >> from >> to;
        if (dist[from][to] < INF)
            cout << dist[from][to] << '\n';
        else
            cout << "-1\n";
    }
}