//PE 70: Totient Permutation
//Problem: Find the greatest value of n lower than 10^7 such that phi(n) is a permutation of n.
//Solution: We can build a sieve with the functions from yesterday, and then just check for every number.
//Note that there is probably a better way, but I'm lazy and it works fast enough.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

long long solve() {
    vector<long long> totient = totient_sieve(10000000);

    double min_val = 1e9;
    long long min_idx = 0;
    for (long long i = 2; i < 10000000LL; i++) {
        string num_str = to_string(i);
        string totient_str = to_string(totient[i]);
        sort(num_str.begin(), num_str.end());
        sort(totient_str.begin(), totient_str.end());

        if (num_str != totient_str)
            continue;

        double curr = (double)(i) / (double)(totient[i]);
        if (curr < min_val) {
            min_val = curr;
            min_idx = i;
        }
    }

    return min_idx;
}

int main() {
    cout << solve() << '\n';
}