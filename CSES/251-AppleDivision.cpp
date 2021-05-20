//Apple division
//Problem: Given n <= 20 weights, find the way of splitting them into two sets such that the difference between them is as small as possible
//Solution: Given that n is so small, we can iterate through every possibility by using bit operations,
//and then keep track of the minimum so far.
//Runtime: O(n * 2^n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long ans = 1e16;
    for (int i = 0; i < (1 << n); i++) {
        long long first = 0, second = 0;
        for (int j = 0; j < n; j++) {
            if (i & 1 << j) {
                first += nums[j];
            } else {
                second += nums[j];
            }
        }

        ans = min(ans, abs(first - second));
    }

    cout << ans << '\n';
}