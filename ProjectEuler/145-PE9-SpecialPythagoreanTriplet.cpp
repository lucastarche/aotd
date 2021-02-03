//PE 9: Special Pythagorean Triplet
//Problem: Given natural numbers a, b and c such that a < b < c, a^2 + b^2 = c^2 and a + b + c = 1000, find a*b*c.
//Solution: We can iterate for each a and b, and find the given c. If a^2 + b^2 = c^2, we return a*b*c.
//Runtime: O(n^2), where n = a + b + c
#include "EulerUtils.hpp"

long long solve() {
    for (long long a = 1; a <= 1000LL; a++) {
        for (long long b = a; b <= 1000LL; b++) {
            long long c = 1000LL - a - b;
            if (a * a + b * b == c * c) {
                return a * b * c;
            }
        }
    }

    return -1; //This should never happen
}

int main() {
    cout << solve() << '\n';
}