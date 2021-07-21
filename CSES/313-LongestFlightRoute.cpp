//Longest Flight Route
//Problem: Given a Directed Acyclic Graph (DAG), find the longest path from 1 to n, or report that there is none
//Solution: We want to modify our toposort algorithm we used yesterday so that we visit the nodes in the right order
//After this, we can use Dynamic Programming by trying to lengthen the path, and keeping track of the parent if we managed to find a longer path
//This works only because our graph has no cycles, since otherwise there would not be a valid toposort, and the longest path would be infinite
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> indegree(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        indegree[to]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!indegree[i])
            q.push(i);

    vector<bool> visit(n + 1);
    vector<int> longest(n + 1, 0);
    vector<int> parent(n + 1, -1);
    longest[1] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visit[curr])
            continue;
        visit[curr] = true;
        for (auto a : adj[curr]) {
            indegree[a]--;
            if (indegree[a] == 0)
                q.push(a);
            if (longest[curr] != 0 && longest[a] < longest[curr] + 1) {
                longest[a] = longest[curr] + 1;
                parent[a] = curr;
            }
        }
    }

    if (!visit[n] || longest[n] == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << longest[n] << '\n';
        stack<int> ans;
        ans.push(n);
        while (parent[ans.top()] != -1) {
            ans.push(parent[ans.top()]);
        }
        while (!ans.empty()) {
            cout << ans.top() << ' ';
            ans.pop();
        }
        cout << '\n';
    }
}