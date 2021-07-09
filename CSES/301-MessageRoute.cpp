//Message Route
//Problem: Given a computer network with n computers and m connections, find the minimum number of computers we need to traverse, or report it is impossible
//Solution: We can represent the network as a graph, with the computers as nodes, and the connections as edges.
//We can then use BFS to find the shortest path from the source to the destination, keeping track of the parent node
//Then we simply print the distance, and reconstruct the path by starting from the end and following the parents
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    queue<int> q;
    q.push(1);
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[1] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto a : adj[curr]) {
            if (dist[a] > dist[curr] + 1) {
                dist[a] = dist[curr] + 1;
                parent[a] = curr;
                q.push(a);
            }
        }
    }

    if (dist[n] == INF) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n] << '\n';

        stack<int> s;
        s.push(n);
        while (parent[n] != -1) {
            s.push(parent[n]);
            n = parent[n];
        }

        while (!s.empty()) {
            cout << s.top() << ' ';
            s.pop();
        }
        cout << '\n';
    }
}