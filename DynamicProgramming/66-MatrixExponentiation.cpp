//Matrix Exponentiation
//We can calculate the value of a matrix to the nth power in a really fast time, thanks to the fact that we can first calculate every power of 2 power, and then multiply the needed ones to get the result.
//One of the most interesting usages is that we can calculate the nth fibonacci number in O(log n).
//Runtime: O(n^3 log x), where x is the power and n is the size of the matrix.
#include <bits/stdc++.h>

using namespace std;

#define IntMatrix vector<vector<int>>

IntMatrix MatrixMultiply(IntMatrix a, IntMatrix b) {
    int n = (int)a.size();
    IntMatrix res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

IntMatrix MatrixExponentiation(IntMatrix mat, int n) {
    IntMatrix res = mat;
    n--;
    while (n > 0) {
        if (n % 2 == 1) {
            res = MatrixMultiply(res, mat);
        }
        mat = MatrixMultiply(mat, mat);
        n /= 2;
    }
    return res;
}

#undef IntMatrix

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> ans = MatrixExponentiation(mat, x);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
