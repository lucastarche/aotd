//Longest Increasing Subsequence: O(n log n) version
//This solves the same problem as yesterday, but works significantly faster, thanks to the fact that we can binary search the answer instead of using linear search.
//The main idea is keeping a list of the last elements of arrays of length 1, 2, 3 ... until the max, with the minimum value posible in the last.
//The runtime is, as stated earlier, O(n log n)
//Note: this video: https://www.youtube.com/watch?v=S9oUiVYEq7E by Tushar Roy explains in a lot more detail than I can fit here.
#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int>& v) {
    int n = (int)v.size();
    int length = 0;
    vector<int> last(n, 0);

    for (int i = 0; i < n; i++) {
        int ans = lower_bound(last.begin(), last.begin() + length, v[i]) - last.begin();
        last[ans] = v[i];
        if (ans + 1 > length)
            length = ans + 1;
    }

    return length;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = LIS(arr);
    cout << "Longest Increasing Subsequence is: " << ans << '\n';
}
