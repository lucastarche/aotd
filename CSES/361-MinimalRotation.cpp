//Minimal Rotation
//Problem: Given a string, find its rotation with the lexicographically minimal value
//Solution: First we will double the string, via which we can now get each rotation as a substring of length exactly n
//We can use Polynomial Hashing to compare whether two strings are equal or not in constant time, after preprocessing the entire string
//The idea is that we have a hash function of the form H(i) = (H(i - 1) * A + s[i]) % B, which enables us to make a range query in constant time
//After this, we iterte through every possible substring of length n, and we compare the order of two strings in O(log n) time
//by performing a binary search in their longest common prefix, and then just comparing the first character which is different
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    s += s;

    long long A = 123, B = 1e9 + 7;
    vector<long long> hash(2 * n + 1), power(2 * n + 1);
    hash[0] = s[0];
    power[0] = 1;

    for (int i = 1; i <= 2 * n; i++) {
        hash[i] = ((hash[i - 1] * A) % B + (long long)s[i]) % B;
        power[i] = (power[i - 1] * A) % B;
    }

    auto getHash = [&](int left, int right) -> long long {
        if (left == 0)
            return hash[right];
        return (hash[right] - (hash[left - 1] * power[right - left + 1]) % B + B) % B;
    };

    int best = 0;
    for (int i = 1; i < n; i++) {
        int left = -1, right = n;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (getHash(best, best + mid) == getHash(i, i + mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (s[best + right] > s[i + right]) {
            best = i;
        }
    }

    cout << s.substr(best, n) << '\n';
}