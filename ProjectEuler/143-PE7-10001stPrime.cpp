//PE7: 10001st prime
//Problem: Find the 10001st prime
//Solution: We generate primes until we have 10001 of them, and return the last one.
//Runtime: O(n * sqrt(n)), where n is the 10001st prime
#include "EulerUtils.hpp"

long long solve() {
    return first_n_primes(10001).back();
}

int main() {
    cout << solve() << '\n';
}