//Copy of AOTD#42
#include "DAG.cpp"

vector<int> toposort(DAG& g) {
    vector<int> order;
    priority_queue<int> pq;
    int n = g.getSize();

    vector<int> indegree(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!g.getIndegree(i))
            pq.push(i);
        indegree[i] = g.getIndegree(i);
    }

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        for (auto a : g.getNeighbours(curr)) {
            indegree[a]--;
            if (indegree[a] == 0)
                pq.push(a);
        }
        order.push_back(curr);
    }

    if ((int)order.size() != n) {
        cerr << "The graph has a cycle" << '\n';
    }

    return order;
}
