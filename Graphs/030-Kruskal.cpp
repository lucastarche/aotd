//Kruskal's algorithm
//Builds a Minimum Spanning Tree, or MST, of the given graph, by using a Union Find Data Structure, also known as a Disjoint Union Set (DSU).
//Runs in O(m log m), because it has to sort all the edges, and then iterate every one of them, which takes O(m inverse_ackerman(m)).
//Another similar algorithm that accomplishes the same task is Prim's algorithm.
#include "GraphWEL.cpp"
#include "UnionFind.cpp"

int Kruskal(GraphWEL &g) {
    int ans = 0, n = g.getSize();
    vector<tuple<int, int, int>> edges = g.getEdges();
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    for (auto e : edges) {
        int w = get<0>(e);
        int from = get<1>(e);
        int to = get<2>(e);
        if (!uf.same(from, to)) {
            uf.unite(from, to);
            ans += w;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    GraphWEL graph(n);
    for (int i = 0; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.addEdge(a, b, w);
    }

    int ans = Kruskal(graph);
    cout << "Minimum Spanning Tree is of weight: " << ans << '\n';
}
