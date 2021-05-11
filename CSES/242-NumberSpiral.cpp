//Number Spiral
//Problem: Given a number spiral, and an x and y, find the number in that position.
//Solution: We can already know the square denoted inside x and y, and then simply add
//the side length to that position.
//Runtime: O(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> y >> x;
        long long side = max(x, y) - 1;
        long long square = side * side;
        if (side % 2 == 1) {
            square += y + (side - x);
        } else {
            square += x + (side - y);
        }

        cout << square + 1 << '\n';
    }
}