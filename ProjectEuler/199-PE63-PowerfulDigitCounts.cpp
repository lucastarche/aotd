//PE 63: Powerful Digit Counts
//Problem: Find the amount of powers of the form a^n that have exactly n digits.
//Solution: We can note that the amount of digits of a^n is floor(n * log10(a)) + 1, by deriving the formula for the number of digits of x, which is floor(log10(x)) + 1
//We can also note that 10^n will always have n + 1 digits, so any number a greater than 9 won't be of use to us.
//Then it is just a matter of iterating through every possible power until we don't find one.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 0;
    bool foundPower = true;
    for (long long i = 1; foundPower; i++) {
        foundPower = false;
        for (long long j = 1; j < 10; j++) {
            long long digits = (long long)(i * log10(j)) + 1;
            if (digits == i) {
                ans++;
                foundPower = true;
            }
        }
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
