//PE 80: Square Root Digital Expansion
//Problem: Find the sum of the first one hundred digits of the decimal expansion of the square roots of the numbers lower than or equal to 100
//Solution: we can binary search the square root to said digits of precision, and then just simply add them all together.
//Note that we need to use bigints to store the required digits.
//Runtime: O(n log n * bigint division)
#include "../lib/bigint.h"
#include "EulerUtils.hpp"

const bigint big10 = 10;

bigint digitSum(bigint n) {
    bigint ans = 0;
    while (n > bigint(0)) {
        ans += (n % big10);
        n /= 10;
    }
    return ans;
}

bigint bigSquareRoot(bigint n, long long digits) {
    bigint limit(1);
    for (int i = 0; i <= digits; i++)
        limit *= big10;
    bigint a(5 * n);
    bigint b(5);

    while (b < limit) {
        if (a >= b) {
            a -= b;
            b += 10;
        } else {
            a *= 100;
            b = (b / big10) * bigint(100) + bigint(5);
        }
    }

    return b / bigint(100);
}

bigint solve() {
    bigint ans = 0;
    for (long long i = 0; i <= 100; i++) {
        long long sqrti = (long long)sqrt(i);
        if (sqrti * sqrti == i)
            continue;
        ans += digitSum(bigSquareRoot(bigint(i), 100));
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}