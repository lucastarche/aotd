//Number Of Paths
//Determines the amount of different paths we can take to get from node 1 to node n, assuming our graph is a DAG.
//We can use DP in a toposorted version, since the number of ways to get to node i is the sum of different ways to get to each of its parents.
//Runtime: O(n + m) or O(n^2), depending on graph implementation.
//Note: we assume that there is no way to reach 1, that is, it has an indegree of 0.
#include "Toposort.cpp"

const int MOD = 1e9 + 7;

int NumberOfPaths(DAG& g) {
    int n = g.getSize();
    vector<int> order = toposort(g);
    vector<int> ways(n + 1, 0);
    ways[1] = 1;
    for (int i = 0; i < n; i++) {
        for (auto node : g.getNeighbours(order[i])) {
            ways[node] += ways[order[i]] % MOD;
            ways[node] %= MOD;
        }
    }

    return ways[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    DAG graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    cout << "The number of different ways to get from 1 to " << n << " is " << NumberOfPaths(graph) << '\n';
}
