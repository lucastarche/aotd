//PE 97: Large Non-Mersenne Prime
//Problem: Find the last ten digits of 28433 * 2^7830457 + 1
//Solution: We can use powmod to get the power part, and then just multiply and add to get the result.
//Note that since the last ten digits is MOD = 1e10, and a long long can only fit up to ~1e18, we have to use
//bigints (although 128 bit integers if those are available).
//Runtime: O(log n), where n is the power.
#include "../lib/bigint.h"
#include "EulerUtils.hpp"

bigint powmod(bigint base, bigint pot, bigint MOD) {
    if (pot == bigint(0))
        return 1;
    else if (pot == bigint(1))
        return base;

    bigint temp = powmod(base, pot / bigint(2), MOD);
    temp *= temp;
    temp %= MOD;

    if (pot % bigint(2) == bigint(1)) {
        temp *= base;
        temp %= MOD;
    }

    return temp;
}

bigint solve() {
    const bigint MOD = (long long)1e10;
    return (powmod(2, 7830457, MOD) * bigint(28433)) % MOD + bigint(1);
}

int main() {
    cout << solve() << '\n';
}