//Naive String Matching
//This algorithm finds a given pattern in a string. However, given that it has two for loops, it runs quite slow on certain cases.
//In a random test input, it runs in O(n). However, we can construct cases in which it goes as bad as O(nm), for example:
//Pattern: AAAB
//Text: AAAAAAAAAAB
//The solution to this problem is the algorithm known as KMP algorithm, short for Knuth-Morris-Pratt algorithm.
#include <bits/stdc++.h>

using namespace std;

vector<int> StringMatching(string& str, string& pattern) {
    vector<int> ans;
    int n = (int)str.size();
    int m = (int)pattern.size();
    for (int i = 0; i < n; i++) {
        bool found = true;
        for (int j = 0; j < m; j++) {
            if (i + j >= n || pattern[j] != str[i + j]) {
                found = false;
                break;
            }

            if (found)
                ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    string str, pattern;
    cin >> str >> pattern;
    auto ans = StringMatching(str, pattern);
    if (ans.empty())
        cout << pattern << " was not found.\n";
    else {
        cout << pattern << " found at positions: ";
        for (auto match : ans)
            cout << match << " ";
        cout << '\n';
    }
}
