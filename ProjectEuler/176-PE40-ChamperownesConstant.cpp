//PE 40: Champerowne's Constant
//Problem: An irrational decimal fraction is created by concatenating every positive integer: 0.123456789101112... . If d(n) is the nth fractional digit of this number, find d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000)
//Solution: We can create a string containing the decimal fraction, and then just get the product as asked. Note that this is only fast if we have constant time string modifications.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 1LL, curr = 1LL;
    string fraction = "";
    while ((long long)fraction.size() < 1000000LL) {
        fraction += to_string(curr);
        curr++;
    }

    for (long long i = 1; i <= 1000000LL; i *= 10LL) {
        ans *= (long long)(fraction[i - 1] - '0');
    }
    
    return ans;
}

int main() {
    cout << solve() << '\n';
}
