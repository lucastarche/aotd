//Max Subarray Product
//Determines the subarray which has the maximum product (duh).
//We can use DP to get a linear solution (vs a O(n^2) naive solution) by keeping track of the max and min values which end in the current index.
//This is because an array with the minimum value can become the max by multiplying by a negative number.
//We can assume an empty array has a product of 1.
//Runtime: O(n)
//Note that we can use O(1) space, thanks to the fact that we just need the previous state to get the current one.
#include <bits/stdc++.h>

using namespace std;

int MaxSubarrayProduct(const vector<int> &nums) {
    int n = (int)nums.size();
    int maxCurr = 1, minCurr = 1, ans = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            maxCurr = minCurr = 1;
        }
        else if (nums[i] > 0) {
            maxCurr *= nums[i];
            minCurr = min(minCurr * nums[i], 1);
        }
        else {
            int buf = maxCurr;
            maxCurr = max(minCurr * nums[i], 1);
            minCurr = buf * nums[i];
        }

        ans = max(ans, maxCurr);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << MaxSubarrayProduct(nums) << '\n';
}