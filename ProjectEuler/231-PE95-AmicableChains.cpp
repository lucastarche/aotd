//PE 95: Amicable Chains
//Problem: We will call an amicable chain a sequence of numbers n1, n2 ... ni such that n1 = ni, and nk is equal to the sum of the divisors of n(k - 1)
//Find the smallest element of the longest amicable chain on which no element exceeds one million.
//Solution: We can calculate the sum of the divisors of all integers under the bound, and then we simply update the longest chain.
//Runtime: O(n sqrt n)
#include "EulerUtils.hpp"

long long solve() {
    vector<long long> divisor_sum(1000001);
    for (int i = 1; i <= 1000000; i++) {
        divisor_sum[i] = accumulate(divisors(i)) - i;
    }

    long long best = 0, ans = 0;
    for (int i = 1; i <= 1000000; i++) {

        vector<int> s;
        int curr = i;
        bool valid = true;

        while (count(s.begin(), s.end(), curr) == 0) {
            s.push_back(curr);
            curr = divisor_sum[curr];
            if (curr > 1000000 || curr == 0) {
                valid = false;
                break;
            }
        }

        if (valid && curr != 0 && s.front() == curr) {
            if ((long long)s.size() > best) {
                best = (long long)s.size();
                int min_val = s[0];
                for (auto a : s) {
                    min_val = min(a, min_val);
                }

                ans = min_val;
            }
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}