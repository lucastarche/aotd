//Book Shop
//Problem: Given an amount of money x and a number of books n, each with a price and a number of pages, find the maximum amount of pages we can buy
//Solution: We can adapt a 01-Knapsack solution to this problem, since on each step we can either buy the current book or not
//Runtime: O(n*x)
//Note: We can also solve this problem with a 1D-DP table instead, since we only need the previous row to solve the current one
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++)
        cin >> books[i].first;
    for (int i = 0; i < n; i++)
        cin >> books[i].second;

    vector<vector<int>> pages(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            int next = j + books[i].first;
            if (next <= x) {
                pages[i + 1][next] = max(pages[i + 1][next], pages[i][j] + books[i].second);
            }
            pages[i + 1][j] = max(pages[i + 1][j], pages[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= x; i++) {
        ans = max(ans, pages[n][i]);
    }
    cout << ans << '\n';
}