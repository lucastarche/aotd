//Christmas tree
//Shows a Christmas tree :D
//Runtime: O(n), unless modificating a string runs in O(n), in which case it is O(n^2).
#include <bits/stdc++.h>

using namespace std;

void ChristmasTree(int levels) {
    string separator = "", branches = "*";
    for (int i = 0; i < levels; i++)
        separator += " ";

    for (int i = 0; i < levels; i++) {
        cout << separator << branches << '\n';
        separator = separator.substr(1);
        branches += "**";
    }

    for (int i = 0; i < levels; i++)
        cout << ' ';
    cout << "|\n";
}

int main() {
    int n;
    cin >> n;
    ChristmasTree(n);
}