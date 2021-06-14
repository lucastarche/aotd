//Subarray Sums 1
//Problem: Given an array of n positive integers, find the number of subarrays such that its sum gives exactly x
//Solution: We can use a combination of prefix sums and the two pointers method to increment the window
//to the right if the sum is under x, or to the left if it is over x.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long sum = 0, ans = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum > x) {
            sum -= nums[l];
            l++;
        }

        if (sum == x) {
            ans++;
            sum -= nums[l];
            l++;
        }
    }

    cout << ans << '\n';
}