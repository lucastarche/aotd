//PE 87: Prime Power Triples
//Problem: Find the amount of numbers under 50000000 such that they can be expressed as the sum of a prime squared, a prime cubed, and a prime to the fourth.
//Solution: Nothing too hard, we simply build a prime list big enough and iterate through each possible prime combination.
//Runtime: O(pi(n)^1/4 * pi(n)^1/3 * pi(n)^1/2) = O(pi(n)^1.083) aprox
#include "EulerUtils.hpp"

long long solve() {
    const long long primeAmount = ceil(sqrt(50000000));
    vector<bool> sieve = prime_sieve(primeAmount);

    vector<long long> primes;
    for (long long i = 2; i <= primeAmount; i++) {
        if (sieve[i])
            primes.push_back(i);
    }

    vector<bool> possible(50000000, false);
    for (auto a : primes) {
        long long a4 = a * a * a * a;
        if (a4 >= 50000000)
            break;
        for (auto b : primes) {
            long long b3 = b * b * b;
            if (a4 + b3 >= 50000000)
                break;
            for (auto c : primes) {
                long long c2 = c * c;
                if (a4 + b3 + c2 >= 50000000)
                    break;
                possible[a4 + b3 + c2] = true;
            }
        }
    }

    return count_if(possible.begin(), possible.end(), [](bool a) { return a; });
}

int main() {
    cout << solve() << "\n";
}