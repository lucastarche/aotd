//PE 36: Double Base Palindromes
//Problem: Find all the numbers that are palindromic in both base 10 and base 2.
//Solution: Not too hard. We just have to test for both conditions. Since we already had a palindrome checker, today we only had to implement a function to parse a number to a binary string.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 0LL;
    for (long long i = 0LL; i < 1000000LL; i++) {
        if (!is_palindrome(i))
            continue;
        if (!is_palindrome(to_binary_string(i)))
            continue;
        ans += i;
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
