//PE3: Largest Prime Factor
//Problem statement: find the largest prime factor of the number 600851475143
//Solution: We first get all the factors of the number, and then return the greatest one.
//For this, we will create a function to add to the utilities header, which is prime_factors(n).
//Runtime: O(sqrt(n))
#include "EulerUtils.hpp"

long long solve() {
    long long num = 600851475143LL;
    set<long long> factors = prime_factors(num);
    return *max_element(factors.begin(), factors.end());
}

int main() {
    cout << solve() << '\n';
}