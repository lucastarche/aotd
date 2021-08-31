//Creating Strings 2
//Problem: Given a string composed of characters in a-z, find the number of different strings we can form with its characters modulo 1e9 + 7
//Solution: The idea is that we count the number of permutations we can arrange the n characters, which is n!,
//and then we divide by k_i! for every i in a-z, where k is the number of times it appears on the string.
//This is because we have to take into account aba and aba are the same string, which wasn't shown in n!
//Note that to divide we have to use modular inverse again
//Runtime: O(n log m), where m is the modulo
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
    string s;
    cin >> s;
    long long n = (long long)s.size();
    vector<long long> chars(26);
    for (auto c : s)
        chars[c - 'a']++;

    vector<long long> factorial(1e6 + 1, 1LL), inverse(1e6 + 1, 1LL);

    for (long long i = 2; i <= 1e6; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
        inverse[i] = powmod(factorial[i], MOD - 2, MOD);
    }

    long long ans = factorial[n];
    for (int i = 0; i < 26; i++) {
        ans = (ans * inverse[chars[i]]) % MOD;
    }

    cout << ans << '\n';
}