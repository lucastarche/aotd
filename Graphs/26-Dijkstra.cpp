//Dijkstra's algorithm
//Starts from a node, and checks if any edge minimizes the distance to any node. However, this algorithm has the limitation that it won't work if there is a negative edge in the graph.
//The reason why we use a priority_queue (or a heap) is because if we have a shorter way to get to a node n, we want to get the shortest value first.
//Runtime: O(n + m log m) with Adjacency List.
//It is a more generalized version of the last aotd, which was BFS.
#include "GraphWAL.cpp"

const int INF = 1e9;

vector<int> Dijkstra(GraphWAL &g, int start) {
    int n = g.getSize();
    priority_queue<pair<int, int>> q;
    vector<int> dist(n + 1, -1);
    vector<bool> processed(n + 1, false);

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        int curr = q.top().second;
        q.pop();
        if (processed[curr]) continue;
        processed[curr] = true;

        for (auto u : g.getNeighbours(curr)) {
            int node = u.second;
            int weight = u.first;
            if (dist[curr] + weight < dist[node]) {
                dist[node] = dist[curr] + weight;
                q.push({-dist[node], node});
            }
        }
    }

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
    vector<int> ans = Dijkstra(graph, source);
    for (int i = 1; i <= n; i++) {
        if (ans[i] < INF) {
            cout << i << " is " << ans[i] << " away from " << source << '\n';
        }
        else cout << i << " is not reachable from " << source << '\n';
    }

}
