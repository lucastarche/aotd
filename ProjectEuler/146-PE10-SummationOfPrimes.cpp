//PE 10: Summation of primes
//Problem: Find the sum of all the primes below 2 million.
//Solution: We can build a prime sieve up to 2 million, and then we add each value if it is prime.
//The prime sieve can be built in pseudo-linear time, as seen in AOTD#68.
//Note that we added a new function, prime_sieve.
//Runtime: O(n log log n)
#include "EulerUtils.hpp"

long long solve() {
    vector<bool> sieve = prime_sieve(2000000LL - 1LL);

    long long ans = 0LL;
    for (long long i = 0; i < 2000000LL; i++) {
        ans += sieve[i] * i;
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}