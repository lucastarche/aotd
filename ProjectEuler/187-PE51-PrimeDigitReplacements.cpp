//PE 51: Prime Digit Replacements
//Problem: Find the smallest prime which, by replacing part of it with the same digit, forms part of an eight prime value family.
//Example: 56**3 forms the prime family of size 6: 56003, 56113, 56333, 56443, 56663, 56993. So 56003 is the smallest prime with this property.
//Solution: First we generate a prime sieve. After this, we iterate through the numbers in base 11, since we add the extra wildcard character.
//After this, it is just a matter of checking how many primes can be formed with the given pattern.
//Runtime: O(n log n)
#include "EulerUtils.hpp" 

long long solve() {
    vector<bool> sieve = prime_sieve(1000000);

    string alphabet = "0123456789*";
    long long pow = 1, powVal10 = 10, powVal11 = 11;
    while (powVal10 < 1000000) {
        pow++;
        powVal10 *= 10LL;
        powVal11 *= 11LL;
    }
    pow = 1;
    powVal10 = 10LL;

    for (long long i = 1LL; i < powVal11; i++) {
        string num = "";
        long long k = i;
        for (long long k = i; k > 0; k /= 11LL) {
            num += alphabet[k % 11LL];
        }
        reverse(num.begin(), num.end());

        bool hasWildcard = false;
        for (auto c : num) if (c == '*') hasWildcard = true;

        if (num[0] == '0' || !hasWildcard) continue;
        pow = num.size();
        
        int curr = 0, j_i = (num[0] == '*');
        long long ret;
        std::string copy = num;
        for (int j = j_i; j < 10; j++) {
            for (int k = 0; k < pow; k++) {
                if (num[k] == '*') copy[k] = '0' + j;
                else copy[k] = num[k];
            }
            if (sieve[stoll(copy)]) curr++;
            if (curr == 1) ret = stoll(copy);
        }
        if (curr >= 8) return ret;
    }

    return -1;
}

int main() {
    cout << solve() << '\n';
}
