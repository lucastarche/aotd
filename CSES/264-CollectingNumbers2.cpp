//Collecting Numbers 2
//Problem: Same as yesterday's, but now we get q queries which tell us to swap a and b
//Solution: We can take advantage of the fact that only two number change from each query to the next, and do a constant
//number of operations to determine the next solution.
//The idea is to see if the new position of the numbers will benefit us, by seeing if
//the previous number is after the current one, and the following is after the current, or not.
//Runtime: O(n + q)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    int ans = 0;
    vector<bool> used(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!used[nums[i] - 1])
            ans++;
        used[nums[i]] = true;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);

        int left = nums[a], right = nums[b];

        if (left != n && a < pos[left + 1] && pos[left + 1] < b)
            ans++;
        if (left != 1 && a < pos[left - 1] && pos[left - 1] < b)
            ans--;
        if (right != n && a < pos[right + 1] && pos[right + 1] < b)
            ans--;
        if (right != 1 && a < pos[right - 1] && pos[right - 1] < b)
            ans++;
        if (left + 1 == right)
            ans++;
        if (left - 1 == right)
            ans--;

        swap(nums[a], nums[b]);
        swap(pos[nums[a]], pos[nums[b]]);
        cout << ans << '\n';
    }
}