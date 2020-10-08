//Floyd-Warshall's algorithm
//Gets the minimum distance between every pair of nodes. It is very easy to implement (just a couple of for loops), but runs quite slowly.
//This is one of the few situations that one may choose an Adjacency Matrix over an Adjacency List.
//Runtime: O(n^3) with Adjacency Matrix
#include "GraphWAM.cpp"

vector<vector<int>> FloydWarshall(GraphWAM &g) {
    int n = g.getSize();
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = g.getDistance(i, j);

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    GraphWAM graph(n);
    for (int i = 0; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.addEdge(a, b, w);
    }

    vector<vector<int>> ans = FloydWarshall(graph);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] != -1)
                cout << ans[i][j] << " ";
            else
                cout << -1 << " ";
        }
        cout << '\n';
    }
}
