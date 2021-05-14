//Bit Strings
//Problem: Given a number n, find the number of different bitstrings of length n that can be formed, modulo 1e9 + 7
//Solution: Since there are n positions, each with two different possibilities, the answer is 2^n.
//For this we can use powmod to get the result quickly.
//Runtime: O(log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    const long long MOD = 1e9 + 7;
    int n;
    cin >> n;

    long long res = 1, base = 2;
    while (n > 0) {
        if (n & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        n >>= 1;
    }

    cout << res << '\n';
}