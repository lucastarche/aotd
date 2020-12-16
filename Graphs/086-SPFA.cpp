//SPFA (Shortes Path Faster Algorithm)
//A better version of Bellman-Ford, which avoids processing repeated stuff. Has all the advantages of it as well.
//Looks like the bastard child of Bellman-Ford and Dijkstra.
//Runtime: O(k*m), where m is the number of edges, and k is a graph-dependant constant such that k <= n
#include "GraphWAL.cpp"

const int INF = 1e9;

vector<int> SPFA(GraphWAL &g, int start) {
    int n = g.getSize();
    vector<int> dist(n + 1, INF);
    queue<int> q;
    vector<bool> enqueued(n + 1, 0);
    vector<int> queueTimes(n + 1, 0);
    dist[start] = 0;
    q.push(start);
    enqueued[start] = true;
    queueTimes[start] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        enqueued[curr] = false;

        for (auto j : g.getNeighbours(curr)) {
            int w = j.first, node = j.second;
            if (dist[curr] + w < dist[node]) {
                dist[node] = dist[curr] + w;
                if (!enqueued[node]) {
                    q.push(node);
                    enqueued[node] = true;
                    queueTimes[node]++;
                }
            }
        }
    }

    bool hasNegativeCycle = false;
    for (int i = 1; i <= n; i++) {
        if (queueTimes[i] >= n) hasNegativeCycle = true;
    }

    if (hasNegativeCycle)
        cerr << "WARNING: The graph has a negative cycle.";

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    GraphWAL graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.addEdge(a, b, w);
    }

    int source;
    cin >> source;
    vector<int> ans = SPFA(graph, source);
    for (int i = 1; i <= n; i++) {
        if (ans[i] < INF) {
            cout << i << " is " << ans[i] << " away from " << source << '\n';
        }
        else cout << i << " is not reachable from " << source << '\n';
    }

}