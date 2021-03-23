//2-SUM
//Determines whether there are exactly two numbers in an array whose sum results in a given number x.
//The naive algorithm runs in O(n^2) by trying every possible two values.
//We can make this much faster by sorting the array first, and used a method known as Two Pointers.
//Runtime: O(n log n).
#include <bits/stdc++.h>

using namespace std;

bool TwoSUM(const vector<int>& nums, int target) {
    int n = (int)nums.size();

    int lptr = 0, rptr = n - 1;
    for (int sum = nums[lptr] + nums[rptr]; sum != target; sum = nums[lptr] + nums[rptr]) {
        if (lptr >= rptr)
            break;
        if (sum > target) {
            rptr--;
        } else {
            lptr++;
        }
    }

    if (nums[lptr] + nums[rptr] == target)
        return true;
    return false;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << TwoSUM(nums, x) << '\n';
}