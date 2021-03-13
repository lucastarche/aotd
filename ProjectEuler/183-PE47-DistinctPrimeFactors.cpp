//PE 47: Distinct Prime Factors
//Problem: Find the first sequence of four integers such that the amount of distinct prime factors is exactly four for each one of them. Return the first one in the sequence.
//Solution: We can use a modified prime sieve, so we can count the number of prime factors, instead of checking whether the number is prime or not.
//Runtime: O(n log log n)
#include "EulerUtils.hpp"

long long solve() {
    vector<int> factors(1000000LL, 0);

    for (long long i = 2; i < 1000000LL; i++) {
        if (factors[i] != 0) continue;
        factors[i] = 1;

        for (long long j = 2 * i; j < 1000000LL; j += i) {
            factors[j]++;
        }
    }

    for (long long i = 1; i < 1000000LL; i++) {
        bool possible = true;
        for (long long j = i; j < i + 4; j++) {
            if (factors[j] != 4) possible = false;
        }
        if (possible) return i;
    }
    return -1;
}

int main() {
    cout << solve() << '\n';
}
