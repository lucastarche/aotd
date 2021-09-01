//Distributing Apples
//Problem: Given n children and m apples, find the different number of ways to distribute the apples between the children
//Solution: The idea is noticing that we have n + m - 1 "boxes", which we can paint either black or white,
//where white represents we give the apple to the current kid, and black we increase the kid number.
//We have exactly m - 1 black boxes, and each way of colouring them describes exactly one state
//The number of ways we can colour them is (n + m - 1)! / (n - 1)! * m!, which is our answer
//Runtime: O(n log m)
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
    vector<long long> factorial(2e6 + 1, 1LL), inverse(2e6 + 1, 1LL);
    inverse[0] = powmod(1, MOD - 2, MOD);
    inverse[1] = inverse[0];

    for (long long i = 2; i <= 2e6; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
        inverse[i] = powmod(factorial[i], MOD - 2, MOD);
    }

    long long n, m;
    cin >> n >> m;
    cout << (factorial[n + m - 1] * inverse[n - 1] % MOD) * inverse[m] % MOD << '\n';
}