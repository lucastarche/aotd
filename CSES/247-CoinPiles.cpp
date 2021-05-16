//Coin Piles
//Problem: Given two piles with a and b coins, determine whether we can remove every coin, if we can remove two from one pile and one from the other on every move.
//Solution: Since we always remove exactly three coins, the sum must always be divisible by three.
//Furthermore, the double of the greatest pile must be no more than the smaller pile, else we cant remove enough coins
//Runtime: O(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 == 0 && (a * 2 >= b && b * 2 >= a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}