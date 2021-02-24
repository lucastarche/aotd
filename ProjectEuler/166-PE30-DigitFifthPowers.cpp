//PE 30: Digit Fifth Powers
//Problem: Find the sum of all the numbers that can be expressed as a sum of the fifth powers of its digits.
//Solution: First we want to get an upper bound for the largest number we could express.
//For this, we want to get a number 999...9 (k times 9) where k * 9^5 < num.
//After this, we just have to find all the numbers with this property under the bound.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

long long sumDigitFifthPower(long long n) {
    long long ans = 0LL;
    while (n > 0LL) {
        long long digit = n % 10LL;
        n /= 10LL;
        ans += (digit * digit * digit * digit * digit);
    }
    return ans;
}

long long solve() {
    long long ans = 0LL;
    long long upper = 9LL;
    while (sumDigitFifthPower(upper) > upper) {
        upper = upper * 10LL + 9LL;
    }

    for (long long i = 10; i <= upper; i++) {
        if (sumDigitFifthPower(i) == i) ans += i;
    }
    
    return ans;
}

int main() {
    cout << solve() << '\n';
}