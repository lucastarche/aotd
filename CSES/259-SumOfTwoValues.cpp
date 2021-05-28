//Sum of Two Values
//Problem: Given an array of n numbers, find the indexes of the two values that sum x, or report it is not possible.
//Solution: We can sort the numbers in increasing order, and then move the left and right until we find the sum, or they cross.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back({ t, i + 1 });
    }

    sort(nums.begin(), nums.end());

    int a = 0, b = n - 1;
    bool found = false;
    while (b - a > 1) {
        int sum = nums[a].first + nums[b].first;
        if (sum == x) {
            cout << nums[a].second << ' ' << nums[b].second << '\n';
            found = true;
            break;
        } else if (sum < x) {
            a++;
        } else {
            b++;
        }
    }

    if (!found)
        cout << "IMPOSSIBLE\n";
}