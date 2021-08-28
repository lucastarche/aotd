//Common Divisors
//Problem: Given a list of n numbers, find the two numbers whose Greatest Common Divisor is as great as possible
//Solution: We can mark each divisor of each number in a list, increasing a counter every time we found it.
//After this, it is just a matter of finding the greatest divisor that appears at least twice, and printing it.
//Runtime: O(n sqrt x), where x is the greatest number in the list
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k = 0;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        k = max(k, nums[i]);
    }

    vector<int> amount(k + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= nums[i]; j++) {
            if (nums[i] % j == 0) {
                amount[j]++;
                if (j != nums[i] / j)
                    amount[nums[i] / j]++;
            }
        }
    }

    for (int j = k; j > 0; j--) {
        if (amount[j] >= 2) {
            cout << j << '\n';
            break;
        }
    }
}