//Counting Divisors
//Problem: Answer q questions of the form "How many different divisors does n have?"
//Solution: We can iterate through every number lower than sqrt(n), and if n % i == 0, we have two extra divisors, i and n / i.
//If the number is also a perfect square we have to add a single divisor, since i = n / i in that case.
//Runtime: O(q sqrt n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    for (int q_i = 0; q_i < q; q_i++) {
        int n;
        cin >> n;
        int sqrt_n = (int)sqrt(n);

        int ans = (sqrt_n * sqrt_n == n);
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0)
                ans += 2;
        }

        cout << ans << '\n';
    }
}