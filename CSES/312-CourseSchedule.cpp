//Course Schedule
//Problem: We are given a list of n courses, and m requirements that state "course a must be finished before course b".
//Find an order in which we can complete the courses, or report it is impossible
//Solution: We want to find a valid toposort of the graph, or report it is impossible if there is none
//For this we can do a BFS, taking care of finding whether there is a cycle or not
//We start from nodes whose indegree is zero, and we delete nodes as we add them to the toposort
//Runtime: O(n + m)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        indegree[to]++;
    }

    queue<int> q;
    vector<bool> visit(n + 1);
    vector<int> toposort;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

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
        }

        toposort.push_back(curr);
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (!visit[i])
            possible = false;
    }

    if (possible) {
        for (auto a : toposort)
            cout << a << ' ';
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}