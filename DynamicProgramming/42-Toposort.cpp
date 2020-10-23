//Toposort
//Orders the nodes in a DAG in such a way that there is no edge that goes backwards, which allows us to sequenciate problems in such a way that we can apply DP.
//It is a modified DFS, so the runtime is O(n + m) with Adjacency List, and O(n^2) with Adjacency Matrix.
#include "DAG.cpp"

vector<int> toposort(DAG &g) {
    vector<int> order;
    priority_queue<int> pq;
    int n = g.getSize();

    vector<int> indegree(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!g.getIndegree(i)) pq.push(i);
        indegree[i] = g.getIndegree(i);
    }


    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        for (auto a : g.getNeighbours(curr)) {
            indegree[a]--;
            if (indegree[a] == 0) pq.push(a);
        }
        order.push_back(curr);
    }

    if (order.size() != n) {
        cerr << "The graph has a cycle" << '\n';
    }

    return order;
}

int main() {
    int n, m;
    cin >> n >> m;
    DAG graph(n);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    vector<int> order = toposort(graph);
    cout << "Toposort: ";
    for (auto a : order) cout << a << " ";
    cout << '\n';
}
