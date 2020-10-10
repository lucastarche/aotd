//Bellman-Ford's algorithm
//Gets the minimum distance between a starting node, and all the other nodes in the graph. It is slower than Dijkstra, but can work with negative edges.
//This algorithm can detect negative cycles, by running one more iteration of the algorithm after calculating all the distances. If we can reduce any distance, then we know such a cycle exists (but not where).
//Runtime: O(n^3) with Adjacency Matrix, O(nm) with Adjacency List
//Note: a negative cycle is a cycle such that the sum of the edges that compone it is lower than zero. This implies that there isn't such a thing as a "shortest path" in this graph, because we can keep making it smaller as much as we want.
#include "GraphWAL.cpp"

const int INF = 1e9;

vector<int> BellmanFord(GraphWAL &g, int start) {
    int n = g.getSize();
    vector<int> dist(n + 1, INF);
    dist[start] = 0;

    for (int i = 1; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto j : g.getNeighbours(u)) {
                int w = j.first, node = j.second;
                dist[node] = min(dist[node], dist[u] + w);
            }
        }
    }

    bool hasNegativeCycle = false;
    for (int u = 1; u <= n; u++) {
        for (auto j : g.getNeighbours(u)) {
            int w = j.first, node = j.second;
            if (dist[node] > dist[u] + w)
                hasNegativeCycle = true;
        }
    }

    if (hasNegativeCycle)
        cerr << "WARNING: The graph has a negative cycle, so SSSP has no meaning.";

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    GraphWAL graph(n);
    for (int i = 0; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.addEdge(a, b, w);
    }

    int source;
    cin >> source;
    vector<int> ans = BellmanFord(graph, source);
    for (int i = 1; i <= n; i++) {
        if (ans[i] < INF) {
            cout << i << " is " << ans[i] << " away from " << source << '\n';
        }
        else cout << i << " is not reachable from " << source << '\n';
    }

}
