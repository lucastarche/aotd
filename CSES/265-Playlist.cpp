//Playlist
//Problem: Given a list of n songs, find the maximum number of songs played without any repetitions.
//Solution: We can use two pointers and a set to keep track of the songs we already listened to.
//When we find a repetition, we erase from the set every element between the left and the right pointer
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    set<int> used;

    int ans = 0;
    for (int lptr = 0, rptr = 0; rptr < n; rptr++) {
        while (used.count(nums[rptr])) {
            used.erase(nums[lptr]);
            lptr++;
        }

        used.insert(nums[rptr]);
        ans = max(ans, (int)used.size());
    }

    cout << ans << '\n';
}