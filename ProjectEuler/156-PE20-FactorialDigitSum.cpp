//PE 20: Factorial Digit Sum
//Problem: Find the sum of the digits of 100! (100 x 99 x 98 x ... x 2 x 1)
//Solution: This is another problem in which we will have to prepare a homemade BigInteger.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long solve() {
    int digits = 1000;
    int order = 0;
    vector<int> num(digits, 0);
    num[0] = 1;

    for (int i = 1; i <= 100; i++) {
        int carry = 0;
        for (int j = 0; j <= order; j++) {
            int prod = i * num[j] + carry;
            num[j] = prod % 10;
            carry = prod / 10;
            if (j == order && carry > 0)
                order++;
        }
    }

    long long ans = 0;
    for (auto digit : num)
        ans += (long long)digit;
    return ans;
}

int main() {
    cout << solve() << '\n';
}
