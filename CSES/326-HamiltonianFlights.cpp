//Hamiltonian Flights
//Problem: Given a directed graph, count the number of different paths from 1 to n which visit every node exactly once
//Solution: We can use a bitmask DP similar to the one used in the Travelling Salesman's Problem
//We will have a 2D DP table, with one dimension being the last node, and the other one a bitmask that keeps track of the used nodes
//Given a pair (i, j), we can go to all pairs with a node adjacent to i, but which aren't turned on in j
//We fill the table, and then print the result in (n - 1, (1 << n) - 1), which represents the nth node, with the mask entirely on
//Runtime: O(n^2 * 2^n)
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> ways(n, vector<int>(1 << n, 0));
    ways[0][1] = 1;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        adj[from].push_back(to);
    }

    for (int j = 0; j < (1 << (n - 1)); j++) {
        for (int i = 0; i < n; i++) {
            if (ways[i][j] == 0)
                continue;
            for (auto a : adj[i]) {
                if (!((1 << a) & j)) {
                    ways[a][j | (1 << a)] += ways[i][j];
                    ways[a][j | (1 << a)] %= MOD;
                }
            }
        }
    }

    cout << ways[n - 1][(1 << n) - 1] << '\n';
}