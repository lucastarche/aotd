//PE 65: Convergents Of E
//Problem: e can be expressed as the continuous fraction [2; 1, 2, 1, 1, 4, 1, 1, 6, ... , 1, 1, 2k, 1, 1 ...].
//Find the sum of the digits of the numerator of the 100th convergent of the continuous fraction of e.
//Solution: First we want to generate the 100 terms of the fraction.
//After this, we can work from right to left, by starting with 1/0. On each iteration, we swap numerator and denominator, and add a * D to the numerator.
//Runtime: O(n * n^2) (the n^2 factor can be made smaller with a better multiplication algorithm for BigIntegers).
//Note that we have to use BigIntegers to prevent overflows.
#include "BigInteger.hpp"
#include "EulerUtils.hpp"

using namespace tarche_num;

long long solve() {
    const long long SIZE = 100;
    stack<long long> s;
    s.push(2);
    s.push(1);

    long long curr = 2;
    while (s.size() < SIZE) {
        s.push(curr);
        s.push(1);
        s.push(1);
        curr += 2;
    }

    while (s.size() > SIZE)
        s.pop();

    BigInteger N = 1, D = 0;
    while (!s.empty()) {
        long long curr = s.top();
        s.pop();
        swap(N, D);
        N += D * curr;
    }

    long long ans = 0;
    for (auto a : N.toString()) {
        ans += (a - '0');
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}