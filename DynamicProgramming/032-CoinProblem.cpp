//Coin Problem
//This is the first example of a Dynamic Programming problem. This is a technique that works similar to Brute Force (test all the posibilities), but is also smart, since it uses "memoization", that is, remembering subproblems that we already solved. A problem can be solved with DP if and only if the problem has optimal subestructures, that is, we can build a solution to a big number tearing it apart to smaller problems.
//The idea behind this algorithm is that, if we can form the value i - c, where c is one of our coins, we can form i with just one extra coin. This is a classical example of a bottom-up DP implementation, since it starts from base cases (0 in this case), and iteratively works until the target value. Another similar way is top-down DP, which is similar to a recursive function, but with the added memo table.
//The runtime is O(nk), where n is the target sum, and k is the amount of coins.
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int CoinProblem(vector<int> &coins, int target) {
    vector<int> table(target + 1, INF);
    table[0] = 0; //We need 0 coins to form $0.
    for (int i = 1; i <= target; i++) {
        for (auto c : coins)
            if (i - c >= 0)
                table[i] = min(table[i], table[i - c] + 1);
    }

    return table[target];
}

int main() {
    int n, target;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    cin >> target;

    int ans = CoinProblem(coins, target);
    if (ans == INF) cout << target << " can't be formed with the given coins." << '\n';
    else cout << target << " can be formed with " << ans << " coins" << '\n';
}
