//PE 27: Quadratic Primes
//Problem: Find the sequence of the form n^2 + a*n + b that generates the most primes starting from n = 0, for |a| < 1000 and |b| <= 1000.
//Solution: We build a big enough prime sieve, and then iterate through every possible pair of a and b, and noting down how many primes we get with each sequence.
//Runtime: O(a * b * n + m log log m), where n is the maximum prime sequence, and m is the size of the sieve we choose.
#include "EulerUtils.hpp"

long long solve() {
    //Max possible value is n^2 + 999*n + 1000.
    //2 million (n = 1000) should be enough
    vector<bool> sieve = prime_sieve(2000000LL);

    long long ans = 0LL, maxLen = 0LL;
    for (long long a = -999LL; a < 1000LL; a++) {
        for (long long b = -1000LL; b <= 1000LL; b++) {
            long long n = 0LL;
            while (true) {
                long long fn = n * n + a * n + b;
                if (fn < 0) break;
                if (!sieve[fn]) break;
                n++;
            }

            if (n > maxLen) {
                maxLen = n;
                ans = a * b;
            }
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}

