//Elevator Rides
//Problem: We have an elevator with a maximum weight x, and n people, each with their weight w_i
//Find the minimum number of rides we need to make, if the sum of the weights in a ride cant exceed x
//Solution: We can use a DP-Bitmask to take advantage of the fact that N <= 20, and that we always have two subsets: those who already were on the elevator and those who were not
//For each possible subset, we can keep track of the weight in the last ride, as well as the minimum number of rides needed
//Then, we can calculate the current mask by trying to mount one of the persons who hasn't already, and making them a new ride if they can't fit
//Runtime: O(n * 2^n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    vector<pair<long long, long long>> dp(1 << n, { n + 1, 0 });
    dp[0] = { 1, 0 };
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                auto curr = dp[mask ^ (1 << i)];
                if (curr.second + weights[i] <= x) {
                    curr.second += weights[i];
                } else {
                    curr.first++;
                    curr.second = weights[i];
                }

                if (curr.first < dp[mask].first || (curr.first == dp[mask].first && curr.second < dp[mask].second)) {
                    dp[mask] = curr;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].first << '\n';
}