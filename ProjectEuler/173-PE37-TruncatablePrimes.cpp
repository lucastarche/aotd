//PE 37: Truncatable Primes
//Problem: Define a prime number to be "truncatable" if we choose either the left or the right, and when we remove a digit from said direction, the number is still prime.
//For example, we have 3797, which all 3797, 379, 37 and 3 are prime (right truncation), as well as 3797, 797, 97 and 7 (left truncation).
//Solution: We will build a prime sieve, and then define two recursive functions, to check if a number is truncatable from the left or from the right.
//Note that the sieve is global for practical reasons, but it could also be passed to the functions instead.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

vector<bool> sieve;

bool isRightTruncatablePrime(long long n) {
    if (n < 10)
        return sieve[n];
    if (!sieve[n])
        return false;
    return isRightTruncatablePrime(n / 10LL);
}

bool isLeftTruncatablePrime(long long n) {
    if (n < 10)
        return sieve[n];
    if (!sieve[n])
        return false;
    long long mod = 1LL;
    while (mod * 10LL < n) {
        mod *= 10LL;
    }
    return isLeftTruncatablePrime(n % mod);
}

bool isTruncatablePrime(long long n) {
    return isRightTruncatablePrime(n) && isLeftTruncatablePrime(n);
}

long long solve() {
    long long ans = 0LL, amount = 0LL;
    sieve = prime_sieve(1000000LL);
    for (long long i = 11; i <= 1000000LL; i += 2) {
        if (isTruncatablePrime(i)) {
            ans += i;
            amount++;
        }

        if (amount == 11LL)
            break;
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
