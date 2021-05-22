//Distinct Numbers
//Problem: Given an array of numbers, find the number of different numbers in the array.
//Solution: We can sort the array, and remove the repetitions.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    auto last = unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());

    cout << nums.size() << '\n';
}