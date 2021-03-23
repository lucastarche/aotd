//PE 6: Sum Square difference
//Problem: Find the difference between (1 + 2 + ... + 100)^2 and 1^2 + 2^2 + 3^2 + ... + 100^2
//Solution: We can get in O(1) the value of (1 + 2 + ... + 100) using a Gauss Summation.
//Then we get the second term in linear time, and return the corresponding difference.
//Note that we added a new function, for the sum of the positive integers between a and b.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long solve() {
    long long sum = range_sum(100LL);
    long long a = sum * sum;
    long long b = 0;

    for (long long i = 1; i <= 100; i++) {
        b += i * i;
    }

    return abs(a - b);
}

int main() {
    cout << solve() << '\n';
}
