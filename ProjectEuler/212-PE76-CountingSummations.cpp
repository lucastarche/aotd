//PE 76: Counting Summations
//Problem: How many ways can 100 be written down as the sum of at least two positive integers?
//Solution: We can use a 2D DP, in which the first dimension represents the target sum, and the second the max number we already used.
//This is so we generate the sums from greatest number to lowest, so we prevent counting the same case more than once.
//Runtime: O(n^2)
#include "EulerUtils.hpp"

vector<vector<long long>> dp(101, vector<long long>(101, 0));

long long get_number_of_ways(long long n, long long max_val) {
    if (n == 0)
        return 1;
    if (dp[n][max_val] != 0)
        return dp[n][max_val];

    long long res = 0;
    for (int i = 1; i <= max_val && i <= n; i++) {
        res += get_number_of_ways(n - i, i);
    }
    dp[n][max_val] = res;
    return res;
}

long long solve() {
    return get_number_of_ways(100, 100) - 1; //The -1 is because we are taking n = n into account
}

int main() {
    cout << solve() << '\n';
}