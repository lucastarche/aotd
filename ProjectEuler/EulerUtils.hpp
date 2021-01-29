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
    reverse_copy(str.begin(), str.end(), copy);
    return str == copy;
}

bool is_palindrome(long long n) {
    return is_palindrome(to_string(n));
}