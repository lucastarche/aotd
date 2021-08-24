//Distinct Colors
//Problem: Given a rooted tree, where each node has a colour, find the number of distinct colours in the subtree of every node
//Solution: We can use the Small-to-Large technique to efficiently merge sets and pass them on to the father
//The idea is that we can merge two sets faster by always moving elements from the smaller set to the bigger
//Then, the idea is that we get the set of colours each subtree has for every node, and after we are done we pass them over to the father
//This is efficient thanks to the StL technique, which prevents worst case O(n^2 log n) behaviour from happening
//Runtime: O(n log^2 n)
#include <bits/stdc++.h>

using namespace std;

struct State {
    vector<vector<int>> adj;
    vector<int> colour;
    vector<int> amount;
};

void merge(set<int>& lhs, set<int>& rhs) {
    //This swap is what makes Small to Large work
    if (lhs.size() < rhs.size())
        swap(lhs, rhs);

    for (auto a : rhs)
        lhs.insert(a);
}

set<int> solve(State& state, int curr, int parent) {
    set<int> s;
    s.insert(state.colour[curr]);
    for (auto a : state.adj[curr]) {
        if (a == parent)
            continue;
        auto ans = solve(state, a, curr);
        merge(s, ans);
    }

    state.amount[curr] = (int)s.size();
    return s;
}

int main() {
    int n;
    cin >> n;

    State state;
    state.adj.resize(n + 1);
    state.colour.resize(n + 1);
    state.amount.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> state.colour[i];

    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        state.adj[from].push_back(to);
        state.adj[to].push_back(from);
    }

    solve(state, 1, -1);
    for (int i = 1; i <= n; i++)
        cout << state.amount[i] << ' ';
    cout << '\n';
}