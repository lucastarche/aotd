//Trailing Zeroes
//Problem: Given a positive integer n, find the number of trailing zeroes that n! has
//Solution: We can see that for each 5 in the product of n!, there is an extra trailing zero.
//Then, we can add floor(n / 5^1) + floor(n / 5^2) + ... + floor(n / 5^k) to get our answer.
//Runtime: O(log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    int val = 5;
    while (val <= n) {
        ans += (n / val);
        val *= 5;
    }

    cout << ans << '\n';
}