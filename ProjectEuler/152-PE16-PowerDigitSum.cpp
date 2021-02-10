//PE 16: Power Digit Sum
//Problem: Get the sum of the digits of 2^1000
//Solution: We can implement a small BigInteger implementation, and then add the digits.
//This problem is way easier in languages which actually have BigIntegers integrated.
//Runtime: O(n^2), where n is the exponent.
#include "EulerUtils.hpp"

long long solve() {
    int order = 0;
    int digits = (int)(1 + 1000 * log(2) / log(10));
    vector<int> num(digits, 0);
    num[0] = 1;

    for (int i = 0; i < 1000; i++) {
        int carry = 0;
        for (int j = 0; j <= order; j++) {
            int prod = 2 * num[j] + carry;
            num[j] = prod % 10;
            carry = prod / 10;
            if (j == order && carry > 0) order++;
        }
    }

    long long ans = 0;
    for (auto digit : num) ans += (long long)digit;
    return ans;
}

int main() {
    cout << solve() << '\n';
}
