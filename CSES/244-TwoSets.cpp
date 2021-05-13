//Two Sets
//Problem: Given a number n, find if there is a way to split the numbers 1..n in two sets, such that the sum of each set is the same
//Solution: It is easy to see that if the sum of the numbers is odd, then we cant do so. This only happens if n % 4 == 1 or n % 4 == 2.
//On the other cases, we can simply find a way, which is adding pairs of terms in such a way that they give n + 1 in the case of n % 4 == 0,
//and that give n in the case n % 4 == 1.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n % 4 == 0) {
        cout << "YES\n"
             << n / 2 << '\n';

        for (int i = 0; i < n / 4; i++) {
            cout << i + 1 << ' ' << n - i << ' ';
        }

        cout << '\n'
             << n / 2 << '\n';

        for (int i = n / 2; i < n / 4; i++) {
            cout << i + 1 << ' ' << n - i << ' ';
        }

        cout << '\n';
    } else if (n % 4 == 3) {
        cout << "YES\n"
             << (n - 1) / 2 << '\n'
             << n << ' ';

        for (int i = 0; i < (n - 1) / 4; i++) {
            cout << i + 1 << ' ' << (n - 1) - i << ' ';
        }

        cout << '\n'
             << (n + 1) / 2 << '\n';
        for (int i = (n - 1) / 4; i < (n + 1) / 2; i++) {
            cout << i + 1 << ' ' << (n - 1) - i << ' ';
        }

        cout << '\n';
    } else {
        cout << "NO\n";
    }
}