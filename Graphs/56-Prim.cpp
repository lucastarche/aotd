//Prim's Algorithm
//It is similar to Kruskal's, and solves the same problem, which is finding a Minimum Spanning Tree of a given graph.
//The main idea is mantaining a priority queue which contains the weight and endpoint of edges, and we greedily select the ones that add a node and don't make new cycles.
//Runtime: O(m log n)
#include "GraphWAL.cpp"

int Prim(GraphWAL &g) {
    int n = g.getSize();
    vector<bool> taken(n + 1);
    priority_queue<pair<int, int>> pq;

    auto process = [&](int node) {
        taken[node] = true;
        for (auto a : g.getNeighbours(node)) {
            if (!taken[a.second])
                pq.push({-a.first, -a.second});
        }
    };

    process(1);
    int ans = 0;
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();
        int weigth = -curr.first;
        int node = -curr.second;
        if (!taken[node]) {
            ans += weigth;
            process(node);
        }
    }

    return ans;
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

    int ans = Prim(graph);
    cout << "Minimum Spanning Tree is of weight: " << ans << '\n';
}
