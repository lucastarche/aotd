//Longest Path
//In a regular or cyclic graph, this question has no sense, given that we can make an arbitrarily long path by using the cycle as much as we want. However, in a DAG it does make sense, and it is what this algorithm calculates.
//The idea is that we toposort the graph, and visit the nodes in reverse order, to visit first the ones which don't have children. Once we have the value of all the children of a node, we can get its value by taking the max and adding one.
//Given that we have to toposort the elements, it runs in O(n + m) with Adjacency List.
#include "Toposort.cpp"

using namespace std;

int LongestPath(DAG &g) {
    int n = g.getSize();
    vector<int> order = toposort(g);
    vector<int> longest(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        longest[order[i]] = 0;
        for (auto node : g.getNeighbours(order[i])) {
            longest[order[i]] = max(longest[order[i]], longest[node] + 1);
        }
    }

    int ans = 0;
    for (auto val : longest) ans = max(ans, val);
    return ans;
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

    cout << "The longest path has length of: " << LongestPath(graph) << '\n';
}
