//Rod Cutting
//Given a list of prices for a rod of length i, and an initial rod of length n, determine the maximum profit we can make.
//We assume cutting the rod is free.
//The idea is that, for each possible length, we calculate the maximum profit we can make out of it.
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int RodCutting(const vector<int> &price, int n) {
    vector<int> memo(n + 1);
    memo[0] = 0;
    for (int j = 1; j <= n; j++) {
        int ans = -INF;
        for (int i = 1; i <= j; i++) {
            ans = max(ans, price[i] + memo[j - i]);
        }
        memo[j] = ans;
    }
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> prices[i];
    cout << RodCutting(prices, n);
}