//PE 75: Singular Integer Right Triangles
//Problem: Find the amount of lengths L such that L <= 1500000, and there exists exactly one right angled integer triangle with perimeter L.
//Solution: We can generate every Pythagorean triple such that the sum of the three numbers is less than 1500000.
//For this, we can use the formula: a = m^2 - n^2, b = 2mn, c = m^2 + n^2, which generates every triple (ka, kb, kc)
//when m and n are integers, m > n, m and n are coprime, and they are not both odd.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

long long solve() {
    vector<int> ways(1500001, 0);
    for (long long m = 1; m * m <= 1500000; m++) {
        for (long long n = m - 1; n > 0; n--) {
            if (gcd(m, n) != 1) //Ensure m and n are coprime...
                continue;
            if (m % 2 == 1 && n % 2 == 1) //And not both odd
                continue;
            long long a = m * m - n * n;
            long long b = 2 * m * n;
            long long c = m * m + n * n;
            for (long long k = 1; k * a + k * b + k * c <= 1500000; k++) {
                ways[k * a + k * b + k * c]++;
            }
        }
    }

    long long ans = 0;
    for (auto a : ways)
        if (a == 1)
            ans++;
    return ans;
}

int main() {
    cout << solve() << '\n';
}