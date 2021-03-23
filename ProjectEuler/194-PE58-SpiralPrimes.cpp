#include "EulerUtils.hpp"

long long solve() {
    long long side = 5LL;
    long long primes = 3LL, diagonals = 5LL;

    while ((double)primes / (double)diagonals > 0.10) {
        long long last = side - 2LL;
        for (long long i = 1LL; i < 4LL; i++) {
            long long curr = last * last + (side - 1LL) * i;
            if (is_prime(curr))
                primes++;
        }

        diagonals += 4LL;
        side += 2LL;
    }

    return side - 2LL;
}

int main() {
    cout << solve() << '\n';
}