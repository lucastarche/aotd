//PE 34: Digit Factorials
//Problem: Find the sum of all numbers which are equal to the sum of the factorials of their digits. (Note: exclude 1 and 2, since 1! and 2! arent sums.)
//Solution: Similar to PE 30, we can find an upper bound, and then process each number up to it. In this case, the bound will be 9 seven times, since 9999999 > 7 * 9!
//Runtime: O(n log n), where n is the upper bound.
#include "EulerUtils.hpp"

vector<long long> memo(10, 1LL);

long long digitFactorial(long long n) {
    long long ans = 0LL;
    while (n > 0LL) {
        ans += memo[n % 10LL];
        n /= 10LL;
    }
    return ans;
}

long long solve() {
    for (long long i = 1; i <= 9; i++) {
        memo[i] = memo[i - 1] * i;
    }

    long long upper = 9LL;
    while (upper <= digitFactorial(upper)) {
        upper = upper * 10LL + 9LL;
    }

    long long ans = 0LL;
    for (long long i = 10LL; i <= upper; i++) {
        if (i == digitFactorial(i)) ans += i;
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
