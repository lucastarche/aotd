//PE 12: Highly Divisible Triangular Number
//Problem: Find the smallest triangular number (Tn = 1 + 2 + ... + n) with more than 500 divisors.
//Solution: We can represent Tn as n * (n + 1) / 2.
//Then we precalculate the amount of divisors of every integer up to a certain point (100000 in this case),
//and we can get the amount of divisors of the triangular numbers in constant time.
//Runtime: O(n log n)
//Note: Thanks to Arkhist for helping me prove the bound :D
#include "EulerUtils.hpp"

long long solve() {
    vector<long long> sieve = divisor_sieve(100000LL);

    long long curr = 1LL;
    while (curr < 100000LL) {
        long long divisors = 0LL;
        if (curr % 2 == 0) {
            divisors = sieve[curr / 2] * sieve[curr + 1];
        } else {
            divisors = sieve[curr] * sieve[(curr + 1) / 2];
        }

        if (divisors > 500LL)
            return (curr * (curr + 1)) / 2;
        curr++;
    }
    return -1; //This should never happen
}

int main() {
    cout << solve() << '\n';
}