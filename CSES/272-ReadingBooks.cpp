//Reading Books
//Problem: Given a list of books, each of which take a duration of t_i seconds to read,
//find the minimum time taken for two people to read all of them, if each person can read one book at a time, and they cant read the same book at the same time.
//Solution: We can sum up all of the time taken to read all of the books, minus the longest one.
//If the time to read the longest one is larger than the sum, it's twice the longest one.
//Else it is sum of all of them
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long longest = *max_element(nums.begin(), nums.end());
    long long sum = accumulate(nums.begin(), nums.end(), -longest);

    if (longest > sum) {
        cout << 2LL * longest << '\n';
    } else {
        cout << sum + longest << '\n';
    }
}