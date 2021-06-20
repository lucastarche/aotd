//Dice Combinations
//Problem: Find the number of different ways to form a sum n by throwing a dice with the numbers 1-6 one or more times.
//Solution: We can use dynamic programming, since the number of ways we can form the sum n is the sum of the number of ways we can form (n - k),
//where k is every possible value for the dice.
//Runtime: O(n * k), where k is the number of sides the dice has.
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> ways(n + 1);
    ways[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j > n)
                break;
            ways[i + j] += ways[i];
            ways[i + j] %= MOD;
        }
    }

    cout << ways[n] << '\n';
}