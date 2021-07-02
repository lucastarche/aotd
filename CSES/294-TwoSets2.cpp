//Two Sets 2
//Problem: Given a number n, find the number of ways to split the numbers into two sets in such a way they both yield equal sum, modulo 1e9 + 7
//Solution: We know that the upper bound for a set is taking every element, that is, n * (n + 1) / 2
//We know that we can form a sum of 0 with 0 elements in a single way
//Then, for each pair of current element and sum, we know that if we can form the sum j with i elements, we can also form the sum j with i + 1 elements,
//as well as the sum j + i + 1with i + 1 elements.
//Note that for outputting the answer we need to add a check so we can divide by two modulo m
//Runtime: O(n^3)
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2) {
        cout << "0\n";
        return 0;
    }

    int upper = n * (n + 1) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(upper + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= upper; j++) {
            dp[i][j] += dp[i - 1][j]; //Ignoring the element
            dp[i][j] %= MOD;

            if (j + i > upper)
                continue;
            dp[i][j + i] += dp[i - 1][j]; //Taking the element
            dp[i][j + i] %= MOD;
        }
    }

    int ans = dp[n][upper / 2];
    if (ans % 2 == 0) {
        cout << ans / 2 << '\n';
    } else {
        cout << (ans + MOD) / 2 << '\n';
    }
}