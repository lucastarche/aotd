//Bracket Sequences 1
//Problem: Given a number n, find the number of valid parentheses expressions with exactly n parentheses
//Solution: Note that this is trivial if n is odd
//If n is even, however, we can use Catalan Numbers, which state the number of valid parentheses expressions with k pairs of parentheses
//C_k = 1/(k + 1) * (2k k) = 2k! / (k + 1 * k! * k!), so we can simply precompute the factorials and their inverses, and print the result
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long powmod(long long a, long long b, long long mod) {
    long long ans = 1LL;
    while (b > 0) {
        if (b & 1LL)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1LL;
    }
    return ans;
}

int main() {
    vector<long long> factorial(1e6 + 1, 1LL), inverse(1e6 + 1, 1LL);
    inverse[0] = powmod(1, MOD - 2, MOD);
    inverse[1] = inverse[0];

    for (long long i = 2; i <= 1e6; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
        inverse[i] = powmod(factorial[i], MOD - 2, MOD);
    }

    long long n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << '\n';
    } else {
        n /= 2;
        cout << powmod(n + 1, MOD - 2, MOD) * factorial[2 * n] % MOD * inverse[n] % MOD * inverse[n] % MOD << '\n';
    }
}