//Knuth-Morris-Pratt's algorithm
//This is a very powerful one, since it provides a linear time algorithm for pattern matching on strings. The idea is taking advantage of the borders of the pattern, so that we don't need to analyze every character in the text more than once.
//It's runtime is O(n + m), which could be stated as just O(n), since m < n, and O(2n) = O(n).
//This is way bettern than the naive version, which worked in O(nm).
#include <bits/stdc++.h>

using namespace std;

//Similar to aotd#47
vector<int> StringBorders(const string &str) {
    int n = (int)str.length();
    vector<int> border(n + 1, 0);

    border[0] = -1;
    int j;
    for (int i = 1; i <= n; i++) {
        j = border[i - 1];
        while (j >= 0) {
            if (str[j] == str[i - 1]) break;
            else j = border[j];
        }

        border[i] = j + 1;
    }

    return border;
}

vector<int> KMP(const string &text, const string &pattern) {
    vector<int> borders = StringBorders(pattern);
    int n = (int)text.length();
    int m = (int)pattern.length();

    if (n < m) return {};

    vector<int> ans;
    int i = 0, k = 0;
    while (i < n) {
        if (text[i] == pattern[k]) {
            i++;
            k++;
            if (k == m) {
                ans.push_back(i - k);
                k = borders[k];
            }
        }
        else {
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
    string str, pattern;
    getline(cin, str);
    getline(cin, pattern);
    auto ans = KMP(str, pattern);
    if (ans.empty()) cout << pattern << " was not found.\n";
    else {
        cout << pattern << " found at positions: ";
        for (auto match : ans) cout << match << " ";
        cout << '\n';
    }
}
