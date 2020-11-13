//Depth First Search (DFS)
//It starts at a certain node, and gets the deepest possible in the graph, before backtracking to earlier unvisited edges.
//Runtime: O(n^2) with Adjacency Matrix, O(n + m) with Adjacency List
//Interesting applications: maze traversal, topological sorting, checking graph connectivity, and much more.
//This is the iterative version, but there is also the (classical) recursive version, which works in a similar way.
#include "GraphAL.cpp"

vector<bool> DFS(GraphAL &g, int start) {
    stack<int> s;
    vector<bool> visited(g.getSize() + 1);
    s.push(start);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        for (auto node : g.getNeighbours(curr)) {
            s.push(node);
        }
    }

    return visited;
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
    vector<bool> ans = DFS(graph, source);
    for (int i = 1; i <= n; i++) {
        if (ans[i]) cout << i << " is reachable from " << source << '\n';
        else cout << i << " is not reachable from " << source << '\n';
    }
}
