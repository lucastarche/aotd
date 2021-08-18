//Tree Matching
//Problem: Given a tree with n nodes, find the maximum number of edges we can choose such that no node belongs to more than one edge
//Solution: This problem can be solved recursively by keeping track of two values per node:
//the maximum number of edges in its subtree if it does not contain the current node, and the maximum number of edges if it does.
//Then, for each node we know that the number of edges without will be the sum of the max for its children,
//and with may include an extra edge if we take use the value without the children for one of its children (say a),
//given that since a and i are free, we can take the edge i->a as well.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

struct State {
    vector<vector<int>> ady;
    vector<int> without;
    vector<int> with;
};

int solve(State& state, int curr, int parent) {
    for (auto& a : state.ady[curr]) {
        if (a == parent)
            continue;

        state.without[curr] += solve(state, a, curr);
    }

    for (auto& a : state.ady[curr]) {
        if (a == parent)
            continue;
        state.with[curr] = max(1 + state.without[curr] - state.with[a] + state.without[a], state.with[curr]);
    }

    return max(state.without[curr], state.with[curr]);
}

int main() {
    int n;
    cin >> n;

    State state;
    state.ady.resize(n + 1);
    state.without.resize(n + 1);
    state.with.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        state.ady[a].push_back(b);
        state.ady[b].push_back(a);
    }

    cout << solve(state, 1, -1) << '\n';
}