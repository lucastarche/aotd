//String Matching
//Problem: Given a string s and a pattern p, count the number of times p appears in s
//Solution: We can use Knuth-Morris-Pratt's algorithm by first calculating the borders of every prefix from the pattern.
//After this, we go from left to right in the string, and try to match it to the pattern, by checking if the characters are equal
//If they are, we keep going until we match the string, but if they are not we skip the border length of the substring we did match
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

vector<int> stringBorders(const string& str) {
    int n = (int)str.length();
    vector<int> border(n + 1, 0);

    border[0] = -1;
    for (int i = 1; i <= n; i++) {
        int j = border[i - 1];
        while (j >= 0) {
            if (str[j] == str[i - 1])
                break;
            else
                j = border[j];
        }

        border[i] = j + 1;
    }

    return border;
}

int KMP(const string& s, const string& p) {
    vector<int> borders = stringBorders(p);
    int n = (int)s.length();
    int m = (int)p.length();

    if (n < m)
        return 0;

    int ans = 0;
    int i = 0, k = 0;
    while (i < n) {
        if (s[i] == p[k]) {
            i++;
            k++;
            if (k == m) {
                ans++;
                k = borders[k];
            }
        } else {
            k = borders[k];
            if (k < 0) {
                i++;
                k++;
            }
        }
    }

    return ans;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << KMP(s, p) << '\n';
}
