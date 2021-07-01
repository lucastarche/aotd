//Removal Game
//Problem: We have two players and an array with n integers. The players take turns and take either the first or last element of the array,
//and add it to their total score. Players try to maximize their score and always play optimally. Find the score of player one
//Solution: We can use minimax in conjunction with Dynamic Programming to compute the differencce between player1 and player2, if they play in the subarray [i, j]
//This can be figured out since the answer is just the opposite of the difference of the next subarray, plus the value they take
//Then, to find the score of player one, we have s1 + s2 = total, and s1 - s2 = dp[0][n - 1].
//We add this two to get 2s1 = total + dp[0][n - 1], and then print this sum divided by two
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

long long solve(vector<vector<long long>>& score, const vector<long long>& nums, int i, int j) {
    if (score[i][j] != -INF)
        return score[i][j];

    score[i][j] = max(
        -solve(score, nums, i + 1, j) + nums[i],
        -solve(score, nums, i, j - 1) + nums[j]);

    return score[i][j];
}

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<long long>> score(n, vector<long long>(n, -INF));
    for (int i = 0; i < n; i++)
        score[i][i] = nums[i];

    long long total = accumulate(nums.begin(), nums.end(), 0LL);

    solve(score, nums, 0, n - 1);
    cout << (total + score[0][n - 1]) / 2 << '\n';
}