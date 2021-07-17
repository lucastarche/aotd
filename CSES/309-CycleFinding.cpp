//Cycle Finding
//Problem: Given a directed graph, determine whether there is a negative cycle, and if so, print an example
//Solution: We can run N iterations of Bellman-Ford's algorithm, keeping track of the parent if we can use a shorter path
//After this, we run one extra iteration until we find a node that we can optimize (aka it is reached by a negative cycle)
//Then we replace it with its nth parent, which needs to be part of a negative cycle.
//Finally, we rebuild the cycle by replacing it with its parent until we reach back to itself.
//Runtime: O(n * m)
//Note that this does not work if there is a self-loop negative cycle, but we can take care of it in the input section
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to;
    long long w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].w;
        if (edges[i].from == edges[i].to && edges[i].w < 0) {
            cout << "YES\n"
                 << edges[i].from << ' ' << edges[i].to << '\n';
            return 0;
        }
        adj[edges[i].from].push_back({ edges[i].to });
    }

    vector<int> parent(n + 1, -1);
    vector<long long> dist(n + 1, 0);

    for (int i = 0; i < n; i++) {
        for (auto& e : edges) {
            if (dist[e.to] > dist[e.from] + e.w) {
                dist[e.to] = dist[e.from] + e.w;
                parent[e.to] = e.from;
            }
        }
    }

    for (auto& e : edges) {
        if (dist[e.to] > dist[e.from] + e.w) {
            cout << "YES\n";
            stack<int> cycle;
            int start = e.to;
            for (int i = 0; i < n; i++)
                start = parent[start];

            cycle.push(start);
            int curr = start;
            do {
                curr = parent[curr];
                cycle.push(curr);
            } while (curr != start);

            while (!cycle.empty()) {
                cout << cycle.top() << ' ';
                cycle.pop();
            }
            cout << '\n';

            return 0;
        }
    }

    cout << "NO\n";
}