//PE 56: Powerful digit sum
//Problem: Find the maximal digit sum of a^b, where 0 <= a, b <= 100
//Solution: We can use a BigInteger yet again, and then try every possible combination.
//Runtime: O(a * b^2 * (log a)^2)  (can be lowered even more, but my BigInteger implementation still has slow multiplication)
#include "EulerUtils.hpp"
#include "BigInteger.hpp"

using namespace tarche_num;

long long solve() {
    long long ans = 0LL;

    for (BigInteger i = 1; i < 100; i++) {
        BigInteger curr(1);
        for (BigInteger j = 1; j < 100; j++) {
            curr *= i;
            long long sum = 0LL;
            for (auto c : curr.toString()) sum += (c - '0');
            ans = max(ans, sum);
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
