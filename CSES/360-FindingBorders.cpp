//Finding Borders
//Problem: Given a string s, find the length of all of its borders (that is, prefixes which are also suffixes)
//Solution: First let us reuse the stringBorders() function from from Knuth-Morris-Pratt's algorithm, which gives us the length of the maximum border of s[1..i]
//Also note that the following is always true: "The border of a border is also a border"
//This is true because if we have s = bab, and set b = cdc, s = cdcacdc, so c is also a border of s
//Then we simply add the last border, which has length i, and we keep adding the length of the border in s[1..i] until i = 1
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

int main() {
    string s;
    cin >> s;
    auto borders = stringBorders(s);
    stack<int> ans;
    ans.push(borders.back());

    while (ans.top() != 0) {
        ans.push(borders[ans.top()]);
    }

    ans.pop();
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << '\n';
}
