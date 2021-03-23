//Pascal's Triangle
//A classical math thing. Can be used to calculate the binomial coefficient in constant time after preprocessing.
//Runtime: O(n^2)

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> PascalTriangle(int n) {
    vector<vector<int>> ret(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                ret[i][j] = 1;
            else {
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
    }

    return ret;
}

int main() {
    int n;
    cin >> n;
    auto ans = PascalTriangle(n);
    for (auto a : ans) {
        for (auto i : a) {
            if (i == 0)
                continue;
            cout << i << ' ';
        }
        cout << '\n';
    }
}