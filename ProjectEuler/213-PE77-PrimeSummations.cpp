//PE 77: Prime Summations
//Problem: Same as yesterday, but we can only use primes to form the sums, and we want to find the first number that has more than 5000 different ways of expressing it.
//Solution: We can just reuse yesterday's solution, but adding a checker to prevent using non-prime numbers.
//Runtime: O(n^2)
#include "EulerUtils.hpp"

const long long PRIME_AMOUNT = 1000000;
vector<bool> sieve = prime_sieve(PRIME_AMOUNT + 1);

vector<vector<long long>> dp(1001, vector<long long>(1001, 0));

long long get_number_of_ways(long long n, long long max_val) {
    if (n == 0)
        return 1;
    long long res = 0;

    for (int i = 1; i <= max_val && i <= n; i++) {
        if (!sieve[i])
            continue;
        res += get_number_of_ways(n - i, i);
    }
    return res;
}

long long solve() {
    for (int i = 1;; i++) {
        //The - sieve[i] is to discard one way if i is prime.
        if ((get_number_of_ways(i, i) - (sieve[i])) > 5000)
            return i;
    }
}

int main() {
    cout << solve() << '\n';
}