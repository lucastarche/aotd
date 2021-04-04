//PE 69: Totient Maximum
//Problem: Eulers totient function (represented by the greek letter phi) returns the number of integers less than n, and that are coprime to n.
//Find the number lower or equal to one million such that n / phi(n) is as big as possible.
//Solution: Once we can calculate phi(n) in a fast time, we can simply iterate through every integer in a range.
//For this we can use a modified sieving algorithm, thanks to the fact that phi(p) = p - 1, phi(p^k) = p^k - p^(k - 1),
//and phi(p1^k1 * p2^k2 * ... * pn^kn) = phi(p1^k1) * phi(p2^k2) * ... * phi(pn^kn), for p prime.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

long long solve() {
    vector<long long> totient = totient_sieve(1000001);

    double max_val = 0.0;
    long long max_idx = 0;
    for (long long i = 2; i <= 1000000LL; i++) {
        double curr = (double)(i) / (double)(totient[i]);
        if (curr > max_val) {
            max_val = curr;
            max_idx = i;
        }
    }

    return max_idx;
}

int main() {
    cout << solve() << '\n';
}