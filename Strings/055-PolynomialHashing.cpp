//Polynomial hashing
//This is one of the many hashing algorithms, which allows various things, including the building of HashSets and HashMaps, and comparing two strings in O(1).
//This special algorithm has the property that once we calculate the hash for the entire string, we can calculate the hash for a substring in constant time, thanks to the formula used to calculate it.
//The formula to calculate the hash of a string is:
//Hash = (s[0]A^(n - 1) + s[1]A^(n - 2) + ... + s[n - 1]A^0) mod B
//Where s[i] indicates the ith character, n is the string length, and A and B are two prechosen constants.
//Runtime: Comparison in O(1), after O(n) preprocessing. However, if there are collisions it could go as high as O(n). This case is highly unlikely, but an attack can be made so it has this complexity.
#include <bits/stdc++.h>

using namespace std;

const int A = 127;
const int B = 1e9 + 7;

int PolynomialHash(string in) {
    int n = (int)in.length();
    vector<int> ans(n);
    ans[0] = in[0];

    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * A % B;
        ans[i] = (ans[i] + in[i]) % B;
    }

    return ans[n - 1];
}

int main() {
    string a, b;
    cin >> a >> b;
    int hashA = PolynomialHash(a);
    int hashB = PolynomialHash(b);
    if (hashA == hashB)
        cout << a << " is equal to " << b << '\n';
    else
        cout << a << " is not equal to " << b << '\n';
}
