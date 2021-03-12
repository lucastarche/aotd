//PE 46: Goldbach's Other Conjecture
//Problem: Find the smallest odd composite number that can not be expressed as the sum of a prime and twice a square
//Solution: We can build a big enough list of primes and square numbers, and then test, for each composite odd number, if some combination of a prime and a square can form it.
//Runtime: O(n * phi(n) * sqrt(n)), where n is the bound we chose.
//Note that phi(n) represents the number of primes under n, and sqrt(n), the amount of squares under n.
#include "EulerUtils.hpp"

long long solve() {
    vector<bool> sieve = prime_sieve(1000001LL);
    vector<long long> primes;
    vector<long long> squares;

    for (long long i = 0; i <= 1000000LL; i++) {
        if (sieve[i]) primes.push_back(i);
    }

    for (long long i = 0LL; i * i <= 1000000LL; i++) {
        squares.push_back(i * i);
    }

    for (long long i = 3LL; i <= 1000000LL; i+=2) {
        if (sieve[i]) continue;
        bool possible = false;

        for (auto p : primes) {
            if (p > i) break;
            for (auto s : squares) {
                long long res = p + 2 * s;
                if (res > i) break;
                if (res == i) possible = true;
            }
            if (possible) break;
        }

        if (!possible) return i;
    }

    //This should never happen
    return -1;
}

int main() {
    cout << solve() << '\n';
}
