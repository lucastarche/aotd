//PE 38: Pandigital Multiples
//Problem: Find the maximum 1-9 pandigital number we can get as the concatenated product of an integer and (1, 2, ..., n), where n > 1.
//Example: The concatenated product of 192 and (1, 2, 3) is 192384576
//Solution: We can set an upper bound of 10000, since n is at least 2, and we can have a maximum of nine digits.
//Then we can iterate through every integer lower than this bound, and see every n possible.
//Runtime: O(n^2 * m * log m), where m is the upper bound, and n is the maximum value for the concatenated product (9)
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 0LL;
    for (long long i = 1LL; i < 10000LL; i++) {
        for (long long j = 2LL; j <= 9LL; j++) {
            long long curr = 0LL;
            for (long long k = 1LL; k <= j; k++) {
                long long prod = i * k, pow = 1LL;
                while (pow < prod)
                    pow *= 10LL;
                curr *= pow;
                curr += prod;
            }

            if (curr >= 1000000000LL)
                break;

            vector<int> digits(10, 0);
            long long copy = curr;
            while (copy > 0LL) {
                digits[copy % 10]++;
                copy /= 10;
            }

            bool isPandigital = (digits[0] == 0);
            for (int i = 1; i < 10; i++) {
                if (digits[i] != 1)
                    isPandigital = false;
            }
            if (isPandigital)
                ans = max(ans, curr);
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
