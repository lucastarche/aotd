//Money Sums
//Problem: Given a list of coins, find all money sums we can form, if we can use each coin at most once
//Solution: We can make a list from [0, sum] which indicates whether we can form the sum k_i or not
//Before doing anything, we mark 0 as possible, since zero coins yield zero sum
//Then, for each coin we have in the list the sums we can form with all coins previous to it, so if we can form k_i, we can form k_i + c
//Note that we need to iterate this list in reverse order, since otherwise we will be counting cases where we use the same coin more than once
//This could also be solved with a 2D table, where one dimension is the current coin, and the sum is the other one
//Runtime: O(n*x), where x is the sum of all coins
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int sum = accumulate(coins.begin(), coins.end(), 0);
    vector<bool> possible(sum + 1, false);
    possible[0] = true;

    for (auto c : coins) {
        for (int j = sum; j >= 0; j--) {
            if (possible[j] && j + c <= sum)
                possible[j + c] = true;
        }
    }

    int ans = accumulate(possible.begin(), possible.end(), -1);
    cout << ans << '\n';
    for (int i = 1; i <= sum; i++)
        if (possible[i])
            cout << i << ' ';
    cout << '\n';
}