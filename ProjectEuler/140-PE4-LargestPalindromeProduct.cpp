//PE4: Largest Palindrome Product
//Problem statement: find the largest product of two three-digit numbers, which is also a palindrome.
//Solution: We can simply iterate through every possible combination for both numbers.
//For this, we will create a function to add to the utilities header, which is called is_palindrome()
//Runtime: O(n^2 * log(n))
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 0LL;

    for (long long i = 100; i <= 999; i++) {
        for (long long j = i; j <= 999; j++) {
            if (is_palindrome(i * j)) {
                ans = max(ans, i * j);
            }
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}