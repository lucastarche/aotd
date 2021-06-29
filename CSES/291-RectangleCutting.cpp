//Rectangle Cutting
//Problem: Given a rectangle of size axb, find the minimum number of cuts needed to cut it into squares
//Solution: We know that a rectangle of axa has solution 0, since it is already a square.
//Then, for every rectangle, we try every possible cut along the vertical and horizontal axis, which yields a result of the sum of the cost of both rectangles plus one.
//Runtime: O(n^3)
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);

    vector<vector<int>> cost(a + 1, vector<int>(b + 1, INF));
    for (int i = 1; i <= a; i++)
        cost[i][i] = 0;

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k < i; k++) {
                cost[i][j] = min(cost[i][j], cost[i - k][j] + cost[k][j] + 1);
            }

            for (int k = 1; k < j; k++) {
                cost[i][j] = min(cost[i][j], cost[i][j - k] + cost[i][k] + 1);
            }
        }
    }

    cout << cost[a][b] << '\n';
}