//Restaurant Customers
//Problem: Given the entry and exit times of n customers, find the max number of customers in the restaurant at the same time.
//Solution: We can have an array with 2n elements: the entry time, the exit time, and the type of event.
//Then we sort by increasing time, and increase by one if it is entry, or decrease if it is exit.
//Note that we have to process every event with equal entry time before updating the max
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, char>> times;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times.push_back({ a, 'A' });
        times.push_back({ b, 'B' });
    }

    sort(times.begin(), times.end());

    int ans = 0, curr = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (times[i].second == 'A') {
            curr++;
        } else {
            curr--;
        }

        if (i == 2 * n - 1 || times[i + 1].first != times[i].first) {
            ans = max(ans, curr);
        }
    }

    cout << ans << '\n';
}