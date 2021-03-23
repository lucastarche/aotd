//Bipartite Check
//It is a modified version of BFS, that checks whether we can color the graph with just two colors or not. This is very easy to do with just two colors, but is NP-Hard with three or more colors.
//A graph is bipartite if and only if there is no cycle with an odd number of members.
//It runs in the same time that BFS, that is, O(n + m) with adjacency list, and O(n^2) with adjacency matrix.
#include "GraphAL.cpp"

bool BipartiteCheck(GraphAL& g) {
    bool isBipartite = true;
    int n = g.getSize();
    vector<int> color(n + 1, 0);
    vector<bool> visited(n + 1);
    queue<int> q;

    q.push(1);
    color[1] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visited[curr])
            continue;
        visited[curr] = true;

        for (auto node : g.getNeighbours(curr)) {
            if (color[node] == color[curr])
                isBipartite = false;
            else if (color[curr] == 2)
                color[node] = 1;
            else
                color[node] = 2;

            q.push(node);
        }
    }

    return isBipartite;
}

int main() {
    int n, m;
    cin >> n >> m;
    GraphAL graph(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    if (BipartiteCheck(graph)) {
        cout << "The graph is bipartite" << '\n';
    } else {
        cout << "The graph is not bipartite" << '\n';
    }
}
