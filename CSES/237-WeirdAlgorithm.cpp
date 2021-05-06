//Weird Algorithm
//Problem: Given an integer n, print n, and if it is even replace it with n / 2, else with 3n + 1.
//Print every number in the sequence until reaching 1
//Solution: Just do as asked, keeping in mind that it may overflow an int in some cases.
//Runtime: O(n) aprox, but since the 3n+1 problem hasn't been solved yet we can't know for sure.
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    while (n != 1LL) {
        cout << n << ' ';
        if (n % 2LL)
            n = (3LL * n) + 1LL;
        else
            n /= 2LL;
    }

    cout << 1 << '\n';
}