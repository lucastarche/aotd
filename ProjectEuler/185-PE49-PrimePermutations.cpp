//PE 49: Prime Permutations
//Problem: Find the arithmetic sequence other than 1487, 4817, 8147, such that it is composed of three four-digit prime numbers, which are all permutations of one another.
//Solution: We can check for every possible pair of starting number and increment, and check whether the conditions hold or not.
//For this, we can sort the numbers parsed to strings, and check if the three are equal or not.
//Runtime: O(n^2 log log n)
#include "EulerUtils.hpp"

long long solve() {
    vector<bool> sieve = prime_sieve(10000LL);
    for (long long i = 1001LL; i < 10000LL; i += 2LL) {
        if (!sieve[i] || i == 1487) continue;
        for (long long j = 1LL; j < 10000LL; j++) {
            long long b = i + j, c = i + 2LL * j;
            if (c >= 10000LL) break;
            if (!sieve[b] || !sieve[c]) continue;
            string a_s = to_string(i), b_s = to_string(b), c_s = to_string(c);
            sort(a_s.begin(), a_s.end());
            sort(b_s.begin(), b_s.end());
            sort(c_s.begin(), c_s.end());

            if (a_s == b_s && a_s == c_s) {
                i *= 10000LL;
                i += b;
                i *= 10000LL;
                i += c;
                return i;
            }
        }
    }

    //This should never happen
    return -1;
}

int main() {
    cout << solve() << '\n';
}
