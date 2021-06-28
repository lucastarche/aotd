//Edit Distance
//Problem: Given two strings, determine the minimum number of operations to equal them, if we can add, remove or replace a character on each operation
//Solution: We know that the edit distance from a string of length i to the empty string is i operations, since we have to remove i characters
//Then, the solution for (i, j) is the minimum of adding a character to a, adding a character to b, or replacing a character from a in b
//Runtime: O(n*m)
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int main() {
    string a, b;
    cin >> a >> b;
    int n = (int)a.size(), m = (int)b.size();

    vector<vector<int>> dist(n + 1, vector<int>(m + 1, INF));
    dist[0][0] = 0;
    for (int i = 1; i <= n; i++)
        dist[i][0] = i;
    for (int j = 1; j <= m; j++)
        dist[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = min(
                dist[i - 1][j] + 1,
                dist[i][j - 1] + 1,
                dist[i - 1][j - 1] + (a[i - 1] == b[j - 1]));
        }
    }

    cout << dist[n][m] << '\n';
}