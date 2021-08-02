//Teleporters Path
//Problem: Given a directed graph, determine whether there is a path from 1 to n that visits every edge exactly once
//Solution: A path like this one only exists if the indegree is one less than the outdegree in node 1,
//the indegree is one more than the indegree in node n, and they are equal in every other node, and if we add edge n->1,
//the graph has a single Strongly Connected Component.
//For this, we can use Kosaraju's algorithm to check the number of SCCs, and then run Hierholzer's algorithm starting from 1 to find the path.
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& adj, vector<int>& order, vector<bool>& visit, int curr) {
    if (visit[curr])
        return;
    visit[curr] = true;
    for (auto a : adj[curr]) {
        dfs(adj, order, visit, a);
    }
    order.push_back(curr);
}

bool sameSCC(vector<vector<int>> adj) {
    int n = (int)adj.size() - 1;
    vector<int> order;
    vector<bool> visit(n + 1);
    adj[n].push_back(1);

    dfs(adj, order, visit, 1);
    reverse(order.begin(), order.end());

    if (!visit[n])
        return false;
    for (int i = 1; i <= n; i++) {
        if (!visit[i] && adj[i].size() > 0) {
            return false;
        }
    }

    vector<vector<int>> rev(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto a : adj[i]) {
            rev[a].push_back(i);
        }
    }

    vector<bool> revVisit(n + 1);
    dfs(rev, order, revVisit, order.back());

    for (int i = 1; i <= n; i++) {
        if (visit[i] != revVisit[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> indegree(n + 1), outdegree(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        indegree[to]++;
        outdegree[from]++;
        adj[from].push_back(to);
    }

    bool valid = true;
    if (!(indegree[1] + 1 == outdegree[1] && indegree[n] == outdegree[n] + 1)) {
        valid = false;
    }

    for (int i = 2; i < n; i++)
        if (indegree[i] != outdegree[i])
            valid = false;

    if (!sameSCC(adj))
        valid = false;

    if (!valid) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    stack<int> path;
    vector<int> circuit;
    path.push(1);

    int curr = 1;
    while (!path.empty()) {
        if (outdegree[curr]) {
            path.push(curr);
            int next = adj[curr].back();
            adj[curr].pop_back();
            outdegree[curr]--;
            curr = next;
        } else {
            circuit.push_back(curr);
            curr = path.top();
            path.pop();
        }
    }

    reverse(circuit.begin(), circuit.end());
    for (auto a : circuit)
        cout << a << ' ';
    cout << '\n';
}