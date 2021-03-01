//PE 35: Circular Primes
//Problem: We will call a prime "circular" if every rotation of its digits is also prime, for example, 197, 971 and 719. Find the amount of circular primes under one million.
//Solution: First we will build a large enough prime sieve, to allow for quick prime checking. After this, we will use a small trick to get every rotation: we will concat two copies of the same number, and we can get all the rotations.
//Example of this: 197197, we can get 197 as [0, 3), 971 as [1, 4), and 719 as [2, 5)
//Runtime: O(n log n)
#include "EulerUtils.hpp"

long long solve() {
    vector<bool> sieve = prime_sieve(1000000LL);

    long long ans = 0LL;
    for (long long i = 0; i <= 1000000LL; i++) {
        if (!sieve[i]) continue;
        string numStr = to_string(i);
        string wrapped = numStr + numStr;

        long long n = (long long)numStr.size();
        bool isCircularPrime = true;
        for (long long j = 1; j < n; j++) {
            if (!sieve[stoll(wrapped.substr(j, n))]) isCircularPrime = false;
        }

        if (isCircularPrime) ans++;
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
