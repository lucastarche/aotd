//PE5: Smallest Multiple
//Problem statement: find the smallest number which can divide all the numbers from 1 to 20.
//Solution: We can see which is the highest power possible of all the primes lower than 20, and then multiply them together.
//For this, we will create a function to add to the utilities header, which is called primes_up_to()
//Runtime: O(n * sqrt(n))
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 1LL;
    vector<long long> primes = primes_up_to(20);

    for (auto i : primes) {
        long long curr = i;
        while (curr * i <= 20LL) {
            curr *= i;
        }
        ans *= curr;
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}