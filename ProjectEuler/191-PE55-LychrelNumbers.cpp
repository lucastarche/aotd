//PE 55: Lychrel Numbers
//Problem: We will call a Lychrel number one such that, if we add its reverse up to fifty times, we never reach a palindromic number. Find the amount of lychrel numbers under ten thousand.
//Example: 349 -> 349 + 943 = 1292 -> 1292 + 2921 = 4213 -> 4213 + 3124 = 7337, so it isnt a lychrel number.
//Solution: We can use a BigInteger implementation, such as the one I have in tarche_num, and then just do as asked.
//Runtime: O(k^2 n log n), where k is the number of iterations, and n is the upper bound.
#include "BigInteger.hpp"
#include "EulerUtils.hpp"

using namespace tarche_num;

long long solve() {
    long long ans = 0LL;
    for (long long i = 1LL; i < 10000LL; i++) {
        bool isLychrelNum = true;
        BigInteger curr(i);
        for (long long iter = 0LL; iter < 50LL; iter++) {
            string s = curr.toString();
            reverse(s.begin(), s.end());
            BigInteger reversed(s);

            curr += reversed;
            if (is_palindrome(curr.toString())) {
                isLychrelNum = false;
                break;
            }
        }
        if (isLychrelNum)
            ans++;
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
