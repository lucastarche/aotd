//PE 78: Coin Partitions
//Problem: Find the smallest integer such that we can partition it in a number of ways that is divisible by 1000000
//Solution: We can use Euler's Pentagonal Number Theorem to get in a fast manner the number of partitions for every integer i.
//For this, we calculate a list with the generalized pentagonal numbers, and then get p(i) as p(i - pent_1) + p(i - pent_2) - p(i - pent_3) - p(i - pent_4) + ...
//Runtime: O(n sqrt n)
#include "EulerUtils.hpp"

long long solve() {
    const long long MOD = 1000000;
    vector<long long> generalized_pentagonals = { 1, 2 };
    for (int i = 2; i < 1000000; i++) {
        generalized_pentagonals.push_back(((3LL * i * i - i) / 2LL));
        generalized_pentagonals.push_back(((3LL * i * i + i) / 2LL));
    }

    vector<long long> p = { 1, 1 };
    for (long long i = 2;; i++) {
        long long curr = 0;
        int ctr = 0;
        for (int j = 0; i >= generalized_pentagonals[j]; j++) {
            if (ctr < 2) {
                curr += p[i - generalized_pentagonals[j]];
            } else {
                curr -= p[i - generalized_pentagonals[j]];
            }

            curr = (curr % MOD + MOD) % MOD;
            ctr++;
            ctr %= 4;
        }

        p.push_back(curr);
        if (curr == 0)
            return i;
    }
}

int main() {
    cout << solve() << '\n';
}