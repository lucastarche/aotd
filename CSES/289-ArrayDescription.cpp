//Array Description
//Problem: We have an array of n integers where each element must be between [1, m], and two consecutive elements differ by at most one
//Find the number of ways we can make a valid array by replacing the zeroes with a number in the range [1, m]
//Solution: We can form a table to see how many ways we can form a valid subarray with the first i elements, if the ith element is equal to j
//Then we add the number of ways we can form a valid array with every element, and the last element being equal to each possible j
//Runtime: O(n*m)
//Note: this is another problem where we can save memory with the space saving trick to use only O(m) memory
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> ways(n, vector<int>(m + 1, 0));
    if (nums[0] == 0) {
        for (int j = 1; j <= m; j++)
            ways[0][j] = 1;
    } else {
        ways[0][nums[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (nums[i] != 0) {
            ways[i][nums[i]] = ways[i - 1][nums[i]];
            if (nums[i] != 1)
                ways[i][nums[i]] += ways[i - 1][nums[i] - 1], ways[i][nums[i]] %= MOD;
            if (nums[i] != m)
                ways[i][nums[i]] += ways[i - 1][nums[i] + 1], ways[i][nums[i]] %= MOD;
            continue;
        }
        for (int j = 1; j <= m; j++) {
            ways[i][j] = ways[i - 1][j];
            if (j != 1)
                ways[i][j] += ways[i - 1][j - 1], ways[i][j] %= MOD;
            if (j != m)
                ways[i][j] += ways[i - 1][j + 1], ways[i][j] %= MOD;
        }
    }

    int ans = accumulate(ways[n - 1].begin(), ways[n - 1].end(), 0, [](int a, int b) -> int {
        return (a + b) % MOD;
    });
    cout << ans << '\n';
}