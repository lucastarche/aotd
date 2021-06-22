//Coin Combinations 1
//Problem: Similar to Dice Combinations, but now we can have different coin denominations, and we want to form a sum of money x
//Solution: We can reuse the code, but now instead of using the range [1, 6] we have to iterate through the array instead
//Runtime: O(n * x)
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> ways(x + 1, 0);
    ways[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (auto c : coins) {
            if (i + c > n)
                break;
            ways[i + c] += ways[i];
            ways[i + c] %= MOD;
        }
    }

    cout << ways[x] << '\n';
}