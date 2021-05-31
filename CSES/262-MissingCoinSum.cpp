//Missing Coin Sum
//Problem: Given a list of coins, find the smallest amount that cant be formed using a subset of these coins.
//Solution: We can sort the coins, and then form the sum incrementally. If the sum is lower than the current coin,
//then the sum + 1 is a value that we cant form.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    sort(coins.begin(), coins.end());

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + 1LL < coins[i])
            break;
        sum += coins[i];
    }

    cout << sum + 1LL << '\n';
}