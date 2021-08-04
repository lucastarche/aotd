//School Dance
//Problem: Given a bipartite graph, find the Maximum Matching, that is, the maximum number of edges we can choose such that no node belongs to more than one edge
//Solution: We can use the Augmenting Path Algorithm for MCBM (Maximum Cardinality Bipartite Matching)
//The idea is the following: We start from a node that does not belong to the matching, and we try finding an Augmenting Path
//This is a path which alternates unmatched, matched, unmatched..., matched, unmatched edges.
//Toggling the edges (unmatched -> matched and viceversa) in the path yields one extra edge
//By Berge's Lemma, when there are no more Augmenting Paths, we have found a Maximum Matching
//Runtime: O(n * m)
#include <bits/stdc++.h>

using namespace std;

struct State {
    vector<vector<int>> ady;
    vector<int> match;
    vector<bool> visited;
};

int augPath(State& state, int k) {
    if (state.visited[k])
        return 0;
    state.visited[k] = true;

    for (auto a : state.ady[k]) {
        if (!state.match[a] || augPath(state, state.match[a])) {
            state.match[a] = k;
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    State state;
    state.ady.resize(n + m + 1);
    state.match.resize(n + m + 1);
    state.visited.resize(n + m + 1);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        b += n;
        state.ady[a].push_back(b);
        state.ady[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            state.visited[j] = false;

        ans += augPath(state, i);
    }

    cout << ans << '\n';
    for (int i = n + 1; i <= n + m; i++) {
        if (state.match[i])
            cout << state.match[i] << ' ' << i - n << '\n';
    }
}