//Exponentiation 2
//Problem: Answer q questions of the form "What is a^(b^c) modulo 1e9 + 7?"
//Solution: We can use Fermat's Little Theorem, which states that a^(p - 1) = 1 (mod p), if a is not a multiple of p
//Note that we will never have a multiple of 1e9 + 7, since a, b, and c are all less or equal to 1e9, and with zero we just return 1
//Therefore, we can get b^c modulo 1e9 + 6, since that will give us a number in the range of [0, 1e9 + 6), after which we can simply do another powmod
//Runtime: O(q log (b + c))
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long powmod(long long a, long long b, long long mod) {
    long long ans = 1LL;
    while (b > 0) {
        if (b % 2LL == 1LL)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2LL;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long k = powmod(b, c, MOD - 1);
        cout << powmod(a, k, MOD) << '\n';
    }
}