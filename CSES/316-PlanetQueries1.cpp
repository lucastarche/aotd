//Planet Queries 1
//Problem: Given a functional graph, answer q queries of the form "Which node will I get to if I start in node i and travel through k edges?"
//Solution: We can use binary lifting to answer the queries in O(log k) time. This idea is that we precalculate the answer for all queries (i, 2^j),
//and then reconstruct the solution by doing binary jumps to reconstruct the asked k.
//For example, for k = 11 we would do a jump of 8, one of 2 and one of 1.
//We can compute these jumps efficiently by using the fact that jumping 2^j times is the same as jumping twice 2^(j - 1) times
//Runtime: O(n log k + q log k), where n is the number of nodes, k is the maximum distance value, and q is the number of queries.
//Note that we need Fast I/O for this problem
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> next(n + 1, vector<int>(31, -1));
    for (int i = 1; i <= n; i++) {
        cin >> next[i][0];
    }

    for (int j = 1; j < 31; j++) {
        for (int i = 1; i <= n; i++) {
            next[i][j] = next[next[i][j - 1]][j - 1];
        }
    }

    for (int q_i = 0; q_i < q; q_i++) {
        int x, k;
        cin >> x >> k;

        for (int j = 0; j < 31; j++) {
            if (k & (1 << j)) {
                x = next[x][j];
            }
        }

        cout << x << '\n';
    }
}