//PE 57: Square Root Convergence
//Problem: We can express sqrt(2) as 1 + 1 / (2 + 1 / (2 + 1 / (2 + ...))). The first expansions are:
//3/2 ; 7/5 ; 17/12 ; 41/29 ; 99/70 ; 239/169 ; 577/408 ; 1393/985
//Find the amount of fractions in the first one thousand expansions, such that the numerator has more digits than the denominator.
//Solution: We can avoid using fractions entirely by expressing the number as a/b.
//On each expansion, b_(n + 1) = a_n + b_n, and a_(n + 1) = a_n + 2 * b_n
//Note that we need to use BigIntegers because else we will overflow.
//Runtime: O(n^2), where n is the number of iterations.
#include "BigInteger.hpp"
#include "EulerUtils.hpp"

using namespace tarche_num;

long long solve() {
    BigInteger a = 3, b = 2;
    long long ans = 0;

    for (int i = 1; i < 1000; i++) {
        BigInteger next_b = a + b;
        a = next_b + b;
        b = next_b;

        if (a.toString().size() > b.toString().size())
            ans++;
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}