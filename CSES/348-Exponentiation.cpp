//Exponentiation
//Problem: Answer q queries of the form "What is a^b mod 1e9 + 7?"
//Solution: We can use binary exponentiation to answer each query in O(log b) time
//The idea is that we multiply our answer by the current base if the last bit of b is turned on,
//and then we square the base and shift b by one to the right, until b = 0
//Runtime: O(q log b)
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long powmod(long long a, long long b, long long mod) {
    long long ans = 1LL;
    while (b > 0) {
        if (b % 2LL == 1LL)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long a, b;
        cin >> a >> b;
        cout << powmod(a, b, MOD) << '\n';
    }
}