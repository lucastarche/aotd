//Giant Pizza
//Problem: Given a list of n toppings and m requests of the form (+- i or +- j), find if there is a way to make a pizza so that every request is accomplished (aka solve 2-SAT or 2-Satisfiability)
//Solution: We will have a graph with 2n nodes: node 2i indicates that we do not choose topping i, while 2i + 1 that we do.
//For each request we can form two edges: +i or -j makes it so if we dont choose i, we cant choose j, or that if we choose j we have to choose i.
//2-SAT is solveable if there is no Strongly Connected Component in the graph such that 2i and 2i + 1 belong to the same component.
//For this we use Kosaraju's algorithm, and we visit the components from biggest to smallest number, choosing the node value for the topping if it does not have one already.
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
    cin >> m >> n;

    vector<vector<int>> adj(2 * n + 2), rev(2 * n + 2);
    for (int i = 0; i < m; i++) {
        char t1, t2;
        int a, b;
        cin >> t1 >> a >> t2 >> b;
        a *= 2;
        b *= 2;
        adj[a + (t1 == '-')].push_back(b + (t2 == '+'));
        rev[b + (t2 == '+')].push_back(a + (t1 == '-'));
        adj[b + (t2 == '-')].push_back(a + (t1 == '+'));
        rev[a + (t1 == '+')].push_back(b + (t2 == '-'));
    }

    vector<int> order;
    vector<bool> visit(2 * n + 2, false);
    for (int i = 2; i <= 2 * n + 1; i++) {
        if (visit[i])
            continue;
        dfs(adj, visit, order, i);
    }

    reverse(order.begin(), order.end());
    vector<int> component(2 * n + 2, 0);

    int k = 0;
    for (auto a : order) {
        if (component[a])
            continue;
        k++;
        dfs2(rev, component, a, k);
    }

    bool possible = true;
    vector<char> result(n + 1, ' ');
    for (int i = 2; i <= 2 * n + 1; i += 2) {
        if (component[i] == component[i + 1])
            possible = false;
        else if (component[i] < component[i + 1])
            result[i / 2] = '+';
        else
            result[i / 2] = '-';
    }

    if (!possible)
        cout << "IMPOSSIBLE\n";
    else {
        for (int i = 1; i <= n; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}