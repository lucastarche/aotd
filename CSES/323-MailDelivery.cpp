//Mail Delivery
//Problem: Find an eulerian circuit which starts at node 1 in an undirected graph, or report it is impossible. (That is, a path which visits all edges)
//Solution: We know a path exists as long as we can reach every edge from node 1, and the degree of each node is even.
//After this, we can use a variation of Hierholzer's algorithm, by constantly adding new edges to the circuit
//Note that since each edge is added at most once, it has a linear runtime.
//Also note that we have a slightly different graph representation to also keep track whether an edge is or not in the circuit
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to;
    bool inCircuit;
};

void dfs(const vector<vector<int>>& adj, const vector<Edge>& edges, vector<bool>& visit, int curr) {
    if (visit[curr])
        return;
    visit[curr] = true;
    for (auto a : adj[curr]) {
        dfs(adj, edges, visit, (curr == edges[a].from) ? edges[a].to : edges[a].from);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> degree(n + 1);
    vector<Edge> edges(m + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(i);
        adj[to].push_back(i);
        degree[from]++;
        degree[to]++;
        edges[i] = {
            from, to, false
        };
    }

    vector<bool> visit(n + 1);
    dfs(adj, edges, visit, 1);

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0 || (!visit[i] && degree[i] != 0)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    stack<int> path;
    vector<int> ans;
    path.push(1);
    int curr = 1;

    while (!path.empty()) {
        if (degree[curr]) {
            int next;
            do {
                next = adj[curr].back();
                adj[curr].pop_back();
                degree[curr]--;
            } while (edges[next].inCircuit && degree[curr] > 0);
            if (degree[curr] == 0 && edges[next].inCircuit) {
                ans.push_back(curr);
                curr = path.top();
                path.pop();
                continue;
            }

            edges[next].inCircuit = true;
            path.push(curr);
            curr = (edges[next].from == curr) ? edges[next].to : edges[next].from;
        } else {
            ans.push_back(curr);
            curr = path.top();
            path.pop();
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto a : ans)
        cout << a << ' ';
    cout << '\n';
}