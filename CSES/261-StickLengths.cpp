//Stick Lengths
//Problem: Given an array of sticks, we want to find the minimal number of operations to get every stick to the same length,
//if we can increase or decrease the length of a stick by one
//Solution: We can find the median, and then sum the differences between every element and the median.
//It can be proven this is always optimal. To find it we can use quickselect, which runs in amortized O(n) time.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());

    long long median = nums[nums.size() / 2];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(nums[i] - median);
    }

    cout << ans << '\n';
}