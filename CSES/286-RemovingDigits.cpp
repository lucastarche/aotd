//Removing Digits
//Problem: Given a number n, we can replace it with the number (n - k), where k is a digit present in n.
//Find the minimum number of steps needed to get to 0
//Solution: We can use DP yet again, since the answer will be the minimum among all the (n - k) for each digit in n, plus one for the operation we do to get there
//Our base case is zero, since we need zero operations to get 0 to 0.
//Runtime: O(n log n), since a number has floor(log10 n) + 1 digits
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int copy = i;
        while (copy > 0) {
            dp[i] = min(dp[i], dp[i - copy % 10] + 1);
            copy /= 10;
        }
    }

    cout << dp[n] << '\n';
}