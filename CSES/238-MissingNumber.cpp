//Missing Number
//Problem: Given a number n, and n - 1 different numbers between 1 and n, find the only number missing in the range.
//Solution: We can keep track of the already seen numbers in the range, and then just print the one which was not found.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> present(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int t;
        cin >> t;
        present[t] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            cout << i << '\n';
            break;
        }
    }
}