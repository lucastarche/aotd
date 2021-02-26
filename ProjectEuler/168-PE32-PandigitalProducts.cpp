//PE 32: Pandigital Products
//Problem: Find the sum of all integers c such that there exists some integers a and b such that a * b = c, and a, b, and c contain the digits 1 through 9 only once between the three.
//Solution: We can iterate through every a and b, and check if the property holds. Note that, since the number of digits is always 9; a and b can have at most 4 digits
//Runtime: O(n^2 log n)
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 0LL;
    map<long long, bool> used;

    for (long long i = 1LL; i < 10000LL; i++) {
        for (long long j = i; j < 10000LL; j++) {
            int totalDigits = 0;
            vector<int> digits(10, 0);
            long long n = i;
            while (n > 0) {
                digits[n % 10]++;
                n /= 10;
                totalDigits++;
            }

            n = j;
            while (n > 0) {
                digits[n % 10]++;
                n /= 10;
                totalDigits++;
            }

            n = i * j;
            while (n > 0) {
                digits[n % 10]++;
                n /= 10;
                totalDigits++;
            }

            if (totalDigits > 9) break;

            bool isPandigital = true;
            if (digits[0] != 0) {
                isPandigital = false;
            }
            for (int i = 1; i <= 9; i++) {
                if (digits[i] != 1) isPandigital = false;
            }

            if (isPandigital) {
                if (used[i * j]) continue;
                used[i * j] = true;
                ans += i * j;
            }
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
