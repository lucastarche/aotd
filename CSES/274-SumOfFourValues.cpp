//Sum Of Four Values
//Problem: Given an array, find the positions of four distinct elements such that their sum is x, or report it is not possible.
//Solution: We can sort the elements, and then try for every pair of indexes i and j if we can form x - arr[i] - arr[j] or not.
//To find this out, we can use the two pointers method, on which we decrease the right pointer if the sum is too great,
//or increase the left one if it is too small.
//Runtime: O(n^3)
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = x - nums[i].first - nums[j].first;
            if (target <= 0)
                break;
            int l = 0, r = n - 1;
            while (l != r) {
                int a = nums[l].first, b = nums[r].first;
                if (a + b == target && l != i && r != i && l != j && r != j) {
                    cout << nums[i].second << ' ' << nums[j].second << ' '
                         << nums[l].second << ' ' << nums[r].second << '\n';
                    goto end;
                } else if (a + b < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
end:
    return 0;
}