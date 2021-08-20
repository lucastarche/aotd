//Tree Distances 1
//Problem: Given a tree, find the length of the longest paths of the form i-x for each and every node i in the tree
//Solution: We can root the tree at an arbitrary node, so we are gonna root it at node 1
//Note that the longest path for any node i goes either downwards to its children, or up through its parent up to a node, and then down again
//First we will calculate the length of the two (different) longest paths downwards for each node i by getting the maximum among the children plus one
//After this, we can get the longest path overall by trying to maximise the length of the children of every node
//This is the reason why we kept the two longest paths downwards: if we go to the children up to the parent and then back down through the same path, it will have repeated edges,
//so we have to take special care when the children is the same via where we maximise the path
//Finally, we make a recursive call to every children, and once we are done we print every length
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

struct State {
    vector<vector<int>> adj;
    vector<pair<int, int>> maxLength1;
    vector<int> maxLength2;
};

int getPathDownwards(State& state, int curr, int parent) {
    for (auto a : state.adj[curr]) {
        if (a == parent)
            continue;
        int ans = getPathDownwards(state, a, curr) + 1;
        if (ans > state.maxLength1[curr].first) {
            state.maxLength2[curr] = state.maxLength1[curr].first;
            state.maxLength1[curr] = { ans, a };
        } else if (ans > state.maxLength2[curr]) {
            state.maxLength2[curr] = ans;
        }
    }

    return state.maxLength1[curr].first;
}

void solve(State& state, int curr, int parent) {
    for (auto a : state.adj[curr]) {
        if (a == parent)
            continue;
        if (state.maxLength1[curr].second == a) {
            if (state.maxLength1[a].first < state.maxLength2[curr] + 1) {
                state.maxLength2[a] = state.maxLength1[a].first;
                state.maxLength1[a] = { state.maxLength2[curr] + 1, curr };
            } else {
                state.maxLength2[a] = max(state.maxLength2[a], state.maxLength2[curr] + 1);
            }
        } else {
            state.maxLength2[a] = state.maxLength1[a].first;
            state.maxLength1[a] = { state.maxLength1[curr].first + 1, curr };
        }

        solve(state, a, curr);
    }
}

int main() {
    int n;
    cin >> n;

    State state;
    state.adj.resize(n + 1);
    state.maxLength1.resize(n + 1);
    state.maxLength2.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        state.adj[from].push_back(to);
        state.adj[to].push_back(from);
    }

    getPathDownwards(state, 1, -1);
    solve(state, 1, -1);
    for (int i = 1; i <= n; i++) {
        cout << state.maxLength1[i].first << ' ';
    }
    cout << '\n';
}
