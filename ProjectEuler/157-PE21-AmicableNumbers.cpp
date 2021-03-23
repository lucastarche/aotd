//PE 21: Amicable Numbers
//Problem: Define d(n) as the sum of proper divisors of n. We will call a and b to be Amicable Numbers if a != b, and d(a) == d(b). Find the sum of all Amicable Numbers up to 10000.
//Solution: First we will make the functions divisors(n), which gives a list of divisors of n, and accumulate(list), which gives the sum of all the numbers in the list.
//Then, we can find for each number if it is amicable or not, and then sum them all up.
//Runtime: O(n * sqrt(n))
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 0LL;

    for (long long i = 1; i <= 10000; i++) {
        long long j = accumulate(divisors(i)) - i;
        if (i == j)
            continue;
        long long k = accumulate(divisors(j)) - j;
        if (i == k)
            ans += i;
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
