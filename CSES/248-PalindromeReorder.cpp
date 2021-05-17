//Palindrome Reorder
//Problem: Given a string of length n, print a palindrome using the same letters, or NO SOLUTION if it is not possible.
//Solution: If there is more than one character which appears an odd number of times it is not possible.
//Else we can form both extremes of the palindrome and then print them one next to the other.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> freq(26, 0);

    for (auto c : s)
        freq[c - 'A']++;

    int amountOdd = 0;
    for (auto a : freq)
        amountOdd += a & 1;

    if (amountOdd > 1) {
        cout << "NO SOLUTION\n";
    } else {
        string half = "", middle = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                middle = string(freq[i], i + 'A');
            } else {
                half += string(freq[i] / 2, i + 'A');
            }
        }

        cout << half << middle;
        reverse(half.begin(), half.end());
        cout << half << '\n';
    }
}