//Fibonacci numbers: fast version
//It turns out, one can use matrix exponentiation to get the nth fibonacci number.
//This is thanks to the fact that the fibonacci sequence is a special case of a linear recurrence, of which we can find the nth term in O(m^3 log n) time, where m is the linear recurrence degree.
//Given that the degree of the fibonacci sequence is 2, the runtime is O(8 log n), which we can then simplify to just O(log n).
//Note: the special matrix for the fibonacci sequence is {{0, 1}, {1, 1}}. This is called the "transformation matrix", about which you can probably find more info on Google.
#include <bits/stdc++.h>

using namespace std;

#define IntMatrix vector<vector<int>>

IntMatrix MatrixMultiply(IntMatrix a, IntMatrix b, int mod) {
    int n = (int)a.size();
    IntMatrix res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] = (res[i][j] % mod + mod) % mod;
            }
        }
    }
    return res;
}

IntMatrix MatrixExponentiation(IntMatrix mat, int n, int mod) {
    IntMatrix res = mat;
    n--;
    while (n > 0) {
        if (n % 2 == 1) {
            res = MatrixMultiply(res, mat, mod);
        }
        mat = MatrixMultiply(mat, mat, mod);
        n /= 2;
    }
    return res;
}

int FibonacciFast(int n, int mod) {
    IntMatrix recurrence = {{0, 1}, {1, 1}};
    IntMatrix ans = MatrixExponentiation(recurrence, n, mod);
    return ans[1][1];
}

#undef IntMatrix

int main() {
    int n, mod;
    cin >> n >> mod;
    cout << FibonacciFast(n, mod) << '\n';
}
