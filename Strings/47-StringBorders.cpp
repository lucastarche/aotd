//String Borders
//Determines the longest substring that isn't the entire string, such that it is both a prefix (ab is a prefix of abcde) and a suffix (de is a prefix of abcde).
//This little algorithm will help when we implement Knuth-Morris-Pratt, since it is a subproblem needed.
//Runtime: O(n).
#include <bits/stdc++.h>

using namespace std;

int LongestBorder(const string &str) {
    int n = (int)str.length();
    vector<int> border(n, 0);

    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && str[i] != str[j]) {
            j = border[j - 1];
        }

        if (str[i] == str[j]) j++;
        border[i] = j;
    }

    return border[n - 1];
}

int main() {
    string in;
    cin >> in;
    int ans = LongestBorder(in);
    cout << "Border of length: " << ans << '\n';
    cout << "Border is string: " << in.substr(0, ans) << '\n';
}
