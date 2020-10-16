//Edit Distance
//Returns the minimum amount of "operations" needed to make a string identical to the other.
//An operation here is defined as either:
//a) Removing a character in any position
//b) Inserting a character in any position
//c) Replacing a character for another in any position
//This algorithm is used for things like Fuzzy Finding.
//It runs in O(3^n). However, this is the non-DP implementation. The DP or tabulated implementation will come tomorrow, which runs in O(nm).
#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int EditDistance(string &a, string &b, int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;
    if (a[n - 1] == b [m - 1]) return EditDistance(a, b, n - 1, m - 1);
    return min(
        EditDistance(a, b, n - 1, m),
        EditDistance(a, b, n, m - 1),
        EditDistance(a, b, n - 1, m - 1)
    );
}

int EditDistance(string &a, string &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    return EditDistance(a, b, n, m);
}

int main() {
    string a, b;
    cin >> a >> b;
    int ans = EditDistance(a, b);
    cout << "The edit distance from " << a << " to " << b << " is " << ans << '\n';
}
