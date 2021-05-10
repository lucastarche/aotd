//Permutations
//Problem: Given an integer n, print a permutation with the elements 1..n, such that no two adjacent numbers have a difference of one.
//Solution: It can be proven that there is no solution if and only if n = 2 or n = 3.
//Otherwise, we can print every even number first, in order, and then every odd number, in order as well.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }

    cout << '\n';
}