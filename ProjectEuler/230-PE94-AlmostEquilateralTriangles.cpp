//PE 94: Almost Equilateral Triangles
//Problem: Find the sum of the perimeter of all triangles with integer perimeter and area, and have two equal sides,
//and the third one differs from these two by a unit.
//Solution: We can use Heron's formula, which says that A = sqrt(s * (s - a) * (s - b) * (s - c)), with s = (a + b + c) / 2
//Replacing with our values we get A = (s - a) * sqrt(s * (s - a +- 1))
//Since this formula has integer solution if and only if both terms are integers, we know that a must be odd.
//Then we just simply have to find all perfect squares of the form s * (s - a +- 1).
//Runtime: O(n)
#include "EulerUtils.hpp"

bool isPerfectSquare(long long n) {
    long long i = sqrt(n);
    for (long long k = i - 2LL; k <= i + 2LL; k++) {
        if (k * k == n)
            return true;
    }
    return false;
}

long long solve() {
    long long ans = 0;
    for (long long a = 3LL; a * 3LL + 10LL < 1000000000LL; a += 2) {
        for (long long k = -1LL; k <= 1LL; k += 2LL) {
            long long s = (a * 3LL + k) / 2LL;
            if (s * 2LL >= 1000000000LL)
                continue;
            if (isPerfectSquare(s * (s - a - k))) {
                ans += s * 2;
            }
        }
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}