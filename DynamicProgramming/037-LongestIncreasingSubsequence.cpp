//Longest Increasing Subsequence: O(n^2) version
//This problem refers to a subsequence, that is, an array that results from deleting some, or all of the elements of the original array, in which every value is greater than the last. This problem is often abreviated as LIS.
//The base case is an array with just one element, since this array will always accomplish the desired property. Then, for each value in the array, we see the ones we already have calculated, and if we can expand the subsequence by one, we do so.
//The runtime is O(n^2), because we make a linear search for each element in the array.
#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> &v) {
    int n = (int)v.size();
    vector<int> len(n, 1);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < k; i++) {
            if (v[i] < v[k]) len[k] = max(len[k], len[i] + 1);
        }
    }

    return *max_element(len.begin(), len.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = LIS(arr);
    cout << "Longest Increasing Subsequence is: " << ans << '\n';
}
