//PE 58: Spiral Primes
//Problem: Given a counter clockwise number spiral, find the side length for which the prime to total numbers in the diagonals first falls below 10%.
//Solution: We can get the numbers in the diagonals as we did in an earlier problem, with the formula (n - 2)^2 + (n - 1) * i for 1 < i <= 4.
//Then, we simply have to check how many of the numbers in the diagonals are prime or not.
//Note that for i = 4, the number is a perfect square, so we can safely skip it, since:
//(n - 2)^2 + (n - 1) * 4 = n^2 - 4n + 4 + 4n - 4 = n^2, which will never be prime
//Runtime: O(n), where n is the side length.
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
