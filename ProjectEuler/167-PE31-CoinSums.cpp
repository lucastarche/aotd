//PE 31: Coin Sums
//Problem: Find the number of ways you can form 200p, given coins of 1p, 2p, 5p, 10p, 20p, 50p, 100p and 200p.
//Solution: This is an easy DP problem, as the one we had solved on aotd#032
//We can get the number of ways one can form i as the sum of the ways one can form (i - c) for every c.
//Runtime: O(k * n), where k is the amount of coins, and n is the target sum.
#include "EulerUtils.hpp"

long long solve() {
    vector<int> ways(201, 0);
    ways[0] = 1; //There is only one way to get 0p

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    for (auto c : coins) {
        for (int i = 0; i <= 200 - c; i++) {
            ways[i + c] += ways[i];
        }
    }

    return ways[200];
}

int main() {
    cout << solve() << '\n';
}
