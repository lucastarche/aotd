//PE 23: Non-Abundant Sums
//Problem: Call a number n if the sum of its proper divisors is greater than n. Find the sum of all the numbers that cant be expressed as the sum of two abundant numbers.
//Note: It is guaranteed that the maximum number that can not be expressed as a sum is under 28123.
//Solution: First we make a list of all the abundant numbers under 30000 (since it is close to 28123), and we build a table with all the sums we can get.
//Then we simply add all the numbers which can not be formed.
//Runtime: O(n^2)
#include "EulerUtils.hpp"

long long solve() {
    vector<long long> abundantNumbers;
    for (long long i = 1; i < 30000LL; i++) {
        if (accumulate(divisors(i)) - i > i) {
            abundantNumbers.push_back(i);
        } 
    }

    int k = (int)abundantNumbers.size();
    vector<bool> possible(30000, false);
    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            long long a = abundantNumbers[i];
            long long b = abundantNumbers[j];
            if (a + b >= 30000LL) break;
            possible[a + b] = true;
        }
    }

    long long ans = 0LL;
    for (long long i = 0; i < 30000LL; i++) {
        if (!possible[i]) {
            ans += i;
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
