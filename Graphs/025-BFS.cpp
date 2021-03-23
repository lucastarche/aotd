//Breadth First Search (BFS)
//Starts from a node, and then visits all the nodes from distance 1 from the origin, then 2, until there are no more nodes.
//Runtime: O(n^2) with Adjacency Matrix, O(n + m) with Adjacency List
//It is the most basic form of pathfinding, but it just works in Unweighed Graphs. A Weighed pathfinding algorithm that is similar is Dijkstra's Algorithm.
#include "GraphAL.cpp"

const int INF = 1e9;

vector<int> BFS(GraphAL& g, int start) {
    queue<int> q;
    vector<int> dist(g.getSize() + 1, -1);
    vector<bool> visited(g.getSize() + 1);
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited[curr] = true;

        for (auto node : g.getNeighbours(curr)) {
            if (visited[node])
                continue;
            q.push(node);
            dist[node] = dist[curr] + 1;
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    GraphAL graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    int source;
    cin >> source;
    vector<int> ans = BFS(graph, source);
    for (int i = 1; i <= n; i++) {
        if (ans[i] != -1) {
            cout << i << " is " << ans[i] << " away from " << source << '\n';
        } else
            cout << i << " is not reachable from " << source << '\n';
    }
}
