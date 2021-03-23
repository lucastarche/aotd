//PE 18: Maximum Path Sum I
//Problem: Given a number triangle, find the path from top to bottom which yields the largest sum.
//Solution: We can use a recursive solution to get the best path from the two childrens of every number, and then add the current number to the best of this two.
//Note that this problem has a lot of overlapping subproblems, and in Problem 67 we have a ton more rows, so we will need to use a DP solution instead.
//Runtime: O(2^n), where n is the number of rows.
#include "EulerUtils.hpp"

long long solve(const vector<vector<long long>>& mat, int i, int j) {
    if (j > i)
        return 0;
    if (i == 14)
        return mat[i][j];
    return mat[i][j] + max(solve(mat, i + 1, j), solve(mat, i + 1, j + 1));
}

long long solve(const vector<vector<long long>>& mat) {
    return solve(mat, 0, 0);
}

int main() {
    ifstream in("input-018.txt");
    vector<vector<long long>> mat(15, vector<long long>(15, 0LL));
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            in >> mat[i][j];
        }
    }

    cout << solve(mat) << '\n';
}
