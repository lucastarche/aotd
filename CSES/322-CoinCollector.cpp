//Coin Collector
//Problem: Given a directed graph with rewards k_i in the ith node, find the maximum reward you can get, if you can only claim the reward of a node once, and can start in any node
//Solution: This is yet another Strongly Connected Components problem, but it is combined with other techniques as well
//First we start by getting the SCCs of the graph, and keeping track of which node belongs to which component
//After this, we generate a condensed graph, on which each node represents a SCC in the original graph, and we link two components if there is an edge from a node in component A to a node in component B in the original graph
//Note that this condensed graph is a DAG, given that if there was a cycle, it would be a SCC, which is a contradiction
//This new graph has rewards equal to the sum of the nodes that belong to the SCC it represents
//Finally, we toposort the DAG and run DP on it, since the best answer for node i is the maximum of the nodes that have an edge to i, plus the value of i
//To end, we print the maximum value possible in the condensed graph
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& adj, vector<bool>& visit, vector<int>& order, int curr) {
    if (visit[curr])
        return;
    visit[curr] = true;
    for (auto a : adj[curr]) {
        dfs(adj, visit, order, a);
    }
    order.push_back(curr);
}

void dfs2(const vector<vector<int>>& adj, vector<int>& component, int curr, int k) {
    if (component[curr])
        return;
    component[curr] = k;
    for (auto a : adj[curr]) {
        dfs2(adj, component, a, k);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> value(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> value[i];

    vector<vector<int>> adj(n + 1), rev(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        rev[to].push_back(from);
    }

    vector<int> order;
    vector<bool> visit(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (visit[i])
            continue;
        dfs(adj, visit, order, i);
    }

    vector<int> component(n + 1);
    reverse(order.begin(), order.end());

    int k = 0;
    for (auto a : order) {
        if (component[a])
            continue;
        k++;
        dfs2(rev, component, a, k);
    }

    vector<long long> component_val(k + 1);
    vector<vector<int>> component_adj(k + 1);
    vector<int> indegree(k + 1);
    for (int i = 1; i <= n; i++) {
        component_val[component[i]] += value[i];
        for (auto a : adj[i]) {
            if (component[i] != component[a]) {
                component_adj[component[i]].push_back(component[a]);
                indegree[component[a]]++;
            }
        }
    }

    queue<int> q;
    vector<long long> ans(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        if (indegree[i] == 0) {
            ans[i] = component_val[i];
            q.push(i);
        }
    }

    vector<bool> component_visit(k + 1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (component_visit[curr])
            continue;
        component_visit[curr] = true;
        for (auto a : component_adj[curr]) {
            ans[a] = max(ans[a], ans[curr] + component_val[a]);
            indegree[a]--;
            if (indegree[a] == 0)
                q.push(a);
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << '\n';
}