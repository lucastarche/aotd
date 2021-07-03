//Increasing Subsequence
//Problem: Given an array, find the longest subsequence such that every element is larger than the previous one
//Solution: We can keep track of the longest subsequence we are able to form in the subarray [0, i - 1),
//in conjunction with the smallest element we've seen in a subsequence of length l.
//Then, we can binary search for the last position whose element is smaller than our currernt element,
//and we expand on said sequence
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int length = 0;
    vector<int> last(n, 0);

    for (int i = 0; i < n; i++) {
        int ans = lower_bound(last.begin(), last.begin() + length, arr[i]) - last.begin();
        last[ans] = arr[i];
        if (ans + 1 > length)
            length = ans + 1;
    }

    cout << length << '\n';
}