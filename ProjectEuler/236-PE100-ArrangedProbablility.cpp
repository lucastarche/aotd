//PE 100: Arranged Probability
//Problem: Given a bag of blue and red discs, find the number of blue discs such that the amount of blue and red discs is
//over 10^12, and there is a 50% chance of taking two blue discs.
//Solution: First we have that n / m * (n - 1) / (m - 1) = 1 / 2
//Distributing we get 2n^2 - 2n + m - m^2 = 1
//Then we simply plug this formula into a quadratic diophantine equation solver to get the formula for every term
//Runtime: O(log n)
#include "../lib/bigint.h"
#include "EulerUtils.hpp"

bigint solve() {
    bigint blue = 85, total = 120;
    bigint bound = (long long)(1e12);

    while (total < bound) {
        bigint tempBlue = 3 * blue + 2 * total - bigint(2);
        bigint tempTotal = 4 * blue + 3 * total - bigint(3);

        blue = tempBlue;
        total = tempTotal;
    }

    return blue;
}

int main() {
    cout << solve() << '\n';
}