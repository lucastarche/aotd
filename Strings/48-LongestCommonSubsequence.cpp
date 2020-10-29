//Longest Common Subsequence
//This problem determines the longest sequence of characters we can form between two strings.
//For example, LCS("hello", "they") = 2, which corresponds to "he".
//This problem is similar to Edit Distance, and can be solved in a similar way.
//Runtime: O(nm).
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int LCS(const string &a, const string &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    vector<vector<int>> table(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) table[i][j] = table[i - 1][j - 1] + 1;
            table[i][j] = max(
                    table[i][j],
                    table[i - 1][j],
                    table[i][j - 1]
            );
        }
    }

    return table[n][m];
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << "LCS is: " << LCS(a, b) << '\n';
}
