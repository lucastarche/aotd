//PE 72: Counting Fractions
//Problem: Count the number of irreducible proper fractions such that the denominator is under 1000000
//Solution: This is quite an easy problem, thanks to the fact that we coded the totient sieve earlier.
//It is just a matter of adding the euler totient of every number under the denominator bound.
//This is because there are phi(n) coprime to n, and less than n, which in fact is also what a proper irreducible fraction is.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

long long solve() {
    vector<long long> sieve = totient_sieve(1000000);
    return accumulate(sieve.begin(), sieve.end(), 0LL);
}

int main() {
    cout << solve() << '\n';
}