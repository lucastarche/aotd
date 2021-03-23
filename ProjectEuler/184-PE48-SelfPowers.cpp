//PE 48: Self Powers
//Problem: Find the last ten digits of 1^1 + 2^2 + 3^3 + ... + 1000^1000
//Solution: We can use powmod to get the last ten digits of each power, and add them all together, to finally extract the last ten digits of that number.
//However, in this case i used iterative exponentiation (without powmod), because otherwise we go out of the C++'s numeric bounds (~2e18)
//Runtime: O(n^2) (would be O(n log n) with powmod)
#include "EulerUtils.hpp"

long long solve() {
    const long long mod = 10000000000LL; //1e10 extracts the last ten digits
    long long ans = 0LL;
    for (long long i = 1; i <= 1000; i++) {
        long long temp = 1;
        for (long long j = 0; j < i; j++)
            temp = (temp * i) % mod;
        ans = (ans + temp) % mod;
    }
    return (long long)ans;
}

int main() {
    cout << solve() << '\n';
}
