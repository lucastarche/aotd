//Square Matrix Multiplication
//This is the Naive algorithm, which consists of just implementing the definition of matrix multiplication.
//There are better algorithms. One of those is Strassen's, which runs in O(n^(2.807)), and we'll see tomorrow.
//The #define is just for making the code a bit more readable.
//Runtime: O(N^3)
#include <bits/stdc++.h>

using namespace std;

#define IntMatrix vector<vector<int>>
IntMatrix MatrixMultiplication(const IntMatrix& A, const IntMatrix& B) {
    int N = (int)A.size();
    IntMatrix C(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}
#undef IntMatrix

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    auto ans = MatrixMultiplication(A, B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}
