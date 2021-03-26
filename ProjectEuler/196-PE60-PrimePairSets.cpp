//PE 60: Prime Pair Sets
//Problem: Find the set of five primes, such that taking any two members and concatenating them yields a prime number, and the sum of its members is the least possible.
//Solution: We will call two primes to be a 'pairing', if concatenating the first and the second in both ways yields a prime number.
//After this, we can iterate through all prime numbers under a certain bound, and then iterate four times through its pairings, skipping if any two primes dont form a pairing.
//Runtime: O(n^2 log log n + n * p(n)^4), where n is the bound, and p(n) is the amount of primes under n that form a pairing with n.
#include "EulerUtils.hpp"

const long long bound = 10000000;
const vector<bool> sieve = prime_sieve(bound);

long long joinNums(long long left, long long right) {
    long long pow = 1;
    while (pow < right) pow *= 10LL;
    return pow * left + right;
}

bool isPairing(long long lower, long long higher) {
    long long lhs = joinNums(lower, higher);
    long long rhs = joinNums(higher, lower);
    if (lhs >= bound || rhs >= bound) return is_prime(lhs) && is_prime(rhs);
    return sieve[lhs] && sieve[rhs];
}

long long solve() {
    vector<long long> primes;
    for (long long i = 3; i < 10000; i += 2) {
        bool isPrime = true;
        for (auto p : primes) {
            if (i < p * p) break;
            if (i % p == 0) isPrime = false;
        }
        if (isPrime) primes.push_back(i);
    }

    int n = (int)primes.size();

    vector<vector<long long>> pairings(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isPairing(primes[i], primes[j])) pairings[i].push_back(primes[j]);
        }
    }

    long long ans = 100000000;
    for (int a = 0; a < n; a++) {
        int k = (int)pairings[a].size();
        for (int b = 0; b < k; b++) {
            int b_k = pairings[a][b];
            for (int c = b + 1; c < k; c++) {
                int c_k = pairings[a][c];
                if (!isPairing(b_k, c_k)) continue;
                for (int d = c + 1; d < k; d++) {
                    int d_k = pairings[a][d];
                    if (!isPairing(b_k, d_k) || !isPairing(c_k, d_k)) continue;
                    for (int e = d + 1; e < k; e++) {
                        int e_k = pairings[a][e];
                        if (!isPairing(b_k, e_k) || !isPairing(c_k, e_k) || !isPairing(d_k, e_k)) continue;
                        long long curr = primes[a] + b_k + c_k + d_k + e_k;
                        ans = min(ans, curr);
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
