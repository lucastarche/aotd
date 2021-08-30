//Binomial Coefficients
//Problem: Answer q questions of the form "What is the value of the binomial coefficient (a b) modulo 1e9 + 7?"
//Note that (a b) = a! / (b! * (a - b)!)
//Solution: We can precompute all the factorials modulo mod, as well as get the modular inverse of them
//This is a way via which we can divide with respect to a modulo
//To compute this, we simply do n^(mod - 2) modulo mod, which always works if n and mod are coprime, thanks to Fermat's Little Theorem
//Then we simply do a! * inv(b!) * inv((a - b)!) modulo mod and print the result
//Runtime: O(x log m + q), where x is the maximum value, and m the modulo
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

long long binomialCoefficient(long long a, long long b) {
    static vector<long long> factorial(1e6 + 1, 1LL), inverse(1e6 + 1, 1LL);
    if (factorial[2] == 1) {
        for (long long i = 2; i <= 1e6; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
            inverse[i] = powmod(factorial[i], MOD - 2, MOD);
        }
    }

    return (factorial[a] * inverse[b] % MOD) * inverse[a - b] % MOD;
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long a, b;
        cin >> a >> b;
        cout << binomialCoefficient(a, b) << '\n';
    }
}