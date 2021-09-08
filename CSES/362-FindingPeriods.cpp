//Finding Periods
//Problem: Given a string s, we call a substring [0..i) of s a period if repeating it enough times (and clamping it when too many characters) yields s
//Solution: This is another problem we can solve using polynomial hashing
//The idea is that, for every period, we try whether the ranges [0..i), [i..2i), [2i..3i], etc. match [0, i),
//and if the remaining substring at the end matches the first few characters of the substring or not
//This can be done efficiently thanks to hashing, thanks to the fact that we can compare two strings in O(1) time
//Runtime: O(n log n), because for period length = 1 we do n comparisons, length = 2 we do ceil(n / 2), and in general we do ceil(n / k) for length = k
//This is equal to about n * H_n, where H_n is the nth harmonic number, which is bounded by log n, so the runtime is O(n log n).
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = (int)s.size();

    long long A = 123, B = 1e9 + 7;
    vector<long long> hash(n + 1), power(n + 1);
    hash[0] = s[0];
    power[0] = 1;

    for (int i = 1; i < n; i++) {
        hash[i] = ((hash[i - 1] * A) % B + (long long)s[i]) % B;
        power[i] = (power[i - 1] * A) % B;
    }

    auto getHash = [&](int left, int right) -> long long {
        if (left == 0)
            return hash[right];
        return (hash[right] - (hash[left - 1] * power[right - left + 1]) % B + B) % B;
    };

    for (int i = 1; i <= n; i++) {
        bool isPeriod = true;

        for (int j = 0; j <= n - i; j += i) {
            if (getHash(j, j + i - 1) != getHash(0, i - 1)) {
                isPeriod = false;
            }
        }

        if (n % i != 0) {
            if (getHash(n - (n % i), n - 1) != getHash(0, n % i - 1)) {
                isPeriod = false;
            }
        }

        if (isPeriod)
            cout << i << ' ';
    }

    cout << '\n';
}