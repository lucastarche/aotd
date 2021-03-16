//PE 50: Consecutive prime sum
//Problem: Find which prime number can be expressed as the sum of the most amount of consecutive prime numbers.
//For example, 41 = 2 + 3 + 5 + 7 + 11 + 13
//Solution: We can make a prime sieve, and then use a sliding window starting from each prime, to see which is the highest amount of primes we can get.
//Runtime: O(phi(n)^2)
#include "EulerUtils.hpp"

long long solve() {
    vector<bool> sieve = prime_sieve(1000000LL);
    vector<long long> primes;
    for (long long i = 0LL; i < (long long)sieve.size(); i++) {
        if (sieve[i]) primes.push_back(i);
    }

    long long ans = 0LL, ansAmount = 0LL;
    long long n = (long long)primes.size();
    for (long long i = 0; i < n; i++) {
        long long sum = 0LL;
        for (long long j = i; j < n; j++) {
            sum += primes[j];
            if (sum > 1000000LL) break;
            if (sieve[sum]) {
                if (j - i > ansAmount) {
                    ansAmount = j - i;
                    ans = sum;
                }
            }
        }
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
