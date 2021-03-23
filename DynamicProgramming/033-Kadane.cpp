//Kadane's algorithm
//It is an efficient DP algorithm that tells us the Max Range Sum or Max Subarray Sum in a 1D array.
//We keep a current sum of the integers, and we set it to zero whenever we go below it (since it is better to have an empty range sum than one that gives a negative number).
//Even though in this implementation we don't use a DP table, we can see that in the ith iteration of the loop, we have in ans the maximum subarray sum in the range [0, i).
//This algorithm is very efficient, as it runs in O(n), being n the number of elements in the array.
#include <bits/stdc++.h>

using namespace std;

int Kadane(vector<int>& v) {
    int current = 0, ans = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        current += v[i];
        ans = max(ans, current);
        current = max(current, 0);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = Kadane(arr);
    cout << "The maximum subarray sum of the array is: " << ans << '\n';
}
