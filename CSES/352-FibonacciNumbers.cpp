//Fibonacci Numbers
//Problem: Given an n <= 1e18, find the nth fibonacci number modulo 1e9 + 7
//Solution: We can represent the Fibonacci Sequence as a linear recurrence, given that Fn = F(n - 1) +  F(n - 2)
//This has a matrix representation of [[0, 1], [1, 1]]
//Then we simply calculate this matrix to the nth power using binary exponentiation
//Runtime: O(log n)
#include <bits/stdc++.h>

using namespace std;

using Mat2x2 = array<array<long long, 2>, 2>;

const long long MOD = 1e9 + 7;

Mat2x2 multiply(Mat2x2 a, Mat2x2 b) {
    Mat2x2 res = { 0, 0, 0, 0 };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}

Mat2x2 binexp(Mat2x2 mat, long long n) {
    Mat2x2 res = mat;
    while (n > 0) {
        if (n % 2LL == 1LL) {
            res = multiply(res, mat);
        }
        mat = multiply(mat, mat);
        n >>= 1LL;
    }
    return res;
}

long long fibonacci(long long n) {
    Mat2x2 recurrence = { 0, 1, 1, 1 };
    Mat2x2 ans = binexp(recurrence, n);
    return ans[0][0];
}

int main() {
    long long n;
    cin >> n;
    cout << fibonacci(n) << '\n';
}
