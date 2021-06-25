//Grid Paths
//Problem: Given a nxn grid, and some squares marked as traps, find the number of different paths from (1, 1) to (n, n) modulo 1e9 + 7 that dont go through a trap
//Solution: We can use DP by adding the two ways of accessing a cell, that is either going down or right
//Note that we do not add the value if it is a trap
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<vector<int>>& dp, vector<vector<bool>>& isTrap, int i, int j) {
    if (isTrap[i][j])
        return -1;
    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = 0;
    if (i != 0) {
        int temp = solve(dp, isTrap, i - 1, j);
        if (temp != -1)
            dp[i][j] += temp, dp[i][j] %= MOD;
    }

    if (j != 0) {
        int temp = solve(dp, isTrap, i, j - 1);
        if (temp != -1)
            dp[i][j] += temp, dp[i][j] %= MOD;
    }

    return dp[i][j];
}

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> isTrap(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            isTrap[i][j] = (s[j] == '*');
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = (!isTrap[0][0]);
    solve(dp, isTrap, n - 1, n - 1);
    cout << ((dp[n - 1][n - 1] == -1) ? 0 : dp[n - 1][n - 1]) << '\n';
}