//PE 41: Pandigital Prime
//Problem: Find the largest 1 to n pandigital number which is also a prime.
//Solution: We can iterate through every possible n, and keep track of the greatest prime we saw so far.
//Note that next_permutation can make our lives a lot easier, since we only iterate through all the pandigital numbers.
//Runtime: O(n! * sqrt(n^10)), where n is the maximum amount of digits (9 in this case)
#include "EulerUtils.hpp"

long long solve() {
    string num = "";
    long long ans = 0LL;
    for (int i = 1; i <= 9; i++) {
        num += i + '0';
        do {
            if (is_prime(stoll(num))) {
                ans = max(ans, stoll(num));
            }
        } while (next_permutation(num.begin(), num.end()));
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
