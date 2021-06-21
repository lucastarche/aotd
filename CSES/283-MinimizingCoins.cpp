//Minimizing Coins
//Problem: Given a list of n coins, and a target sum x, find the minimum number of coins needed to form the sum. We can use each coin as much as we want
//Solution: We can use dp to try minimizing the sum, since if we can form the sum k, we can form k + c with dp[k] + 1 coins.
//Runtime: O(n*x)
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int i = 0; i <= x; i++) {
        if (dp[i] >= INF)
            continue;
        for (auto a : coins) {
            if (i + a > x)
                continue;
            dp[i + a] = min(dp[i] + 1, dp[i + a]);
        }
    }

    if (dp[x] == INF)
        cout << "-1\n";
    else
        cout << dp[x] << '\n';
}