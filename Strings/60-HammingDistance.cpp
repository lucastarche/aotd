//Hamming Distance
//The Hamming Distance is the number of positions at which the characters of two strings are different.
//This is very basic, but is used in coding theory for error detection.
//Runtime: O(n)
//Note: There is also a way faster way, that relies on bitwise operators and bit counts, but only works on binary stirngs.
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int HammingDistance(string &a, string &b) {
    int ans = 0;
    if (a.length() != b.length()) return INF;

    for (int i = 0; i < (int)a.length(); i++) {
        if (a[i] != b[i]) ans++;
    }

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    int ans = HammingDistance(a, b);
    if (ans >= INF) cout << "The strings have different lengths." << '\n';
    else cout << "The hamming distance is: " << ans << '\n';
}
