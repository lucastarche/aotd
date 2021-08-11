//Forest Queries
//Problem: Given a board with NxN tiles, which may or may not have a tree in them, find the number of trees in the rectangle with corners (x1, y1) and (x2, y2)
//Solution: We can use a 2D Prefix Sum table to get the sum from (0, 0) to (x, y) in constant time
//We can build this table in O(n^2) time, since (i, j) = (i - 1, j) + (i, j - 1) - (i - 1, j - 1) + isTree(i, j)
//After this, we simply answer the queries by using the formula prefix[x2][y2] + prefix[x1 - 1][y1 - 1] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2]
//Runtime: O(n^2 + q)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<char>> forest(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }

    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j] + (forest[i][j] == '*');
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] + prefix[x1 - 1][y1 - 1] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] << '\n';
    }
}