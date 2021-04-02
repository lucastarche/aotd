//PE 67: Maximal Path Sum II
//Problem: Identical to PE 18, but with tighter bounds. Find the path from top to bottom which yields the highest sum across it.
//Solution: We can use a DP solution, by using the recursive formula: dp[i][j] = mat[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]), which represents going down from the best of the two parents, plus the current cell.
//Runtime: O(n^2)
#include "EulerUtils.hpp"

long long solve(const vector<vector<long long>> &mat) {
    vector<vector<long long>> dp(100, vector<long long>(100, 0LL));
    dp[0][0] = mat[0][0];
    for (int i = 1; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = mat[i][j] + dp[i - 1][j];
            else if (j == i) dp[i][j] = mat[i][j] + dp[i - 1][j - 1];
            else dp[i][j] = mat[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    long long ans = 0LL;
    for (auto a : dp[99]) ans = max(ans, a);
    return ans;
}

int main() {
    ifstream in("input-067.txt");
    vector<vector<long long>> mat(100, vector<long long>(100, 0LL));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            in >> mat[i][j];
        }
    }
    cout << solve(mat) << '\n';
}
