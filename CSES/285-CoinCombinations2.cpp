//Coin Combinations 2
//Problem: We want to form the sum of money x with different coins of amount k
//Count the different number of ways we can form said sum if the coins must be in increasing order.
//Solution: We can reuse the code from yesterday, but we inverse the order in which we iterate coins and numbers
//This works because we always add the smaller coins before the bigger ones, so the resulting ways are in order
//Note that we can also consider this problem in 2D with the dimensions (index_of_biggest_coin, sum_of_money)
//Runtime: O(n * x + n log n)
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    sort(coins.begin(), coins.end());

    vector<int> ways(x + 1, 0);
    ways[0] = 1;
    for (auto c : coins) {
        for (int i = 0; i <= n; i++) {
            if (i + c > n)
                break;
            ways[i + c] += ways[i];
            ways[i + c] %= MOD;
        }
    }

    cout << ways[x] << '\n';
}