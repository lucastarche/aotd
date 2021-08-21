//Company Queries 1
//Problem: Given a rooted tree, answer q queries of the form "Find the kth boss of x"
//Solution: We can use binary lifting to keep track of the ks which are powers of two
//After this, we can compose every k as a sum of different powers of two to get the answer
//Runtime: O(n log n + q log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int size = floor(log2(n)) + 1;
    vector<vector<int>> boss(n + 1, vector<int>(size + 1, 0));

    for (int i = 2; i <= n; i++) {
        cin >> boss[i][0];
    }

    for (int j = 1; j < size; j++) {
        for (int i = 1; i <= n; i++) {
            boss[i][j] = boss[boss[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < size; j++) {
            if (k & (1 << j))
                x = boss[x][j];
        }
        if (x == 0)
            cout << "-1\n";
        else
            cout << x << '\n';
    }
}