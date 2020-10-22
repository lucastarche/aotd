//Grid Paths 
//Gets the maximum value possible to get to the bottom right corner of a matrix with values, assuming we start in the top right, and we can only move down and right.
//As many other 2D DP algorithms, it runs in O(nm).
#include <bits/stdc++.h>

using namespace std;

long long GridPaths(vector<vector<int>> &mat) {
    int n = (int)mat.size();
    int m = (int)mat[0].size();
    vector<vector<int>> table(n, vector<int>(m));

    table[0][0] = mat[0][0];

    for (int i = 1; i < n; i++) {
        table[i][0] = table[i - 1][0] + mat[i][0];
    }

    for (int j = 1; j < m; j++) {
        table[0][j] = table[0][j - 1] + mat[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            table[i][j] = max(
                table[i - 1][j], 
                table[i][j - 1]
            ) + mat[i][j];
        }
    }

    return table[n - 1][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    cout << "The smallest value to get to the bottom right is " << GridPaths(matrix) << '\n';
}