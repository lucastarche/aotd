#include <bits/stdc++.h>

using namespace std;

set<long long> prime_factors(long long n) {
    set<long long> ans;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            ans.insert(i);
        }
    }

    if (n > 2LL) ans.insert(n);

    return ans;
}

bool is_palindrome(string str) {
    string copy;
    reverse_copy(str.begin(), str.end(), copy.begin());
    return str == copy;
}

bool is_palindrome(long long n) {
    return is_palindrome(to_string(n));
}

vector<long long> primes_up_to(long long n) {
    vector<long long> primes = {2LL};

    for (long long i = 3; i <= n; i += 2) {
        bool isPrime = true;
        for (auto p : primes) {
            if (i % p == 0) {
                isPrime = false;
                break;
            }
            if (p * p > i) break;
        }

        if (isPrime) primes.push_back(i);
    }

    return primes;
}

long long range_sum(long long n) {
    return (n * (n + 1LL)) / 2LL;
}

long long range_sum(long long a, long long b) {
    return range_sum(b) - range_sum(a);
}

vector<long long> first_n_primes(long long n) {
    vector<long long> primes = {2LL};
    long long curr = 3LL;
    while (primes.size() < n) {
        bool isPrime = true;
        for (auto p : primes) {
             if (curr % p == 0LL) {
                 isPrime = false;
                 break;
             }
             if (p * p > curr) break;
        }
        if (isPrime) primes.push_back(curr);
        curr += 2LL;
    }
    return primes;
}

vector<bool> prime_sieve(long long n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    
    for (long long i = 2; i <= n; i++) {
        if (!sieve[i]) continue;
        for (long long j = 2 * i; j <= n; j += i) {
            sieve[j] = false;
        }
    }

    return sieve;
}

vector<long long> divisor_sieve(long long n) {
    vector<long long> sieve(n + 1, 1);
    sieve[0] = 0;
    
    for (long long i = 2; i <= n; i++) {
        for (long long j = i; j <= n; j += i) {
            sieve[j]++;
        }
    }
    
    return sieve;
}

vector<long long> divisors(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != (long long)(n / i)) {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

long long accumulate(vector<long long> nums) {
    long long ans = 0LL;
    for (auto n : nums) ans += n;
    return ans;
}

long long factorial(long long n) {
    long long ans = 1LL;
    for (long long i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
