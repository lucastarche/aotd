//Creating Strings
//Problem: Given a string of length n <= 8, print every string that can be formed with its characters.
//Solution: We can simply sort the string, and then print every single permutation of its characters.
//Runtime: O(n!)
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    int ctr = 0;
    do {
        ctr++;
    } while (next_permutation(s.begin(), s.end()));

    cout << ctr << '\n';
    do {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
}