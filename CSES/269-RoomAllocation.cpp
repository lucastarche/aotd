//Room Allocation
//Problem: Given a list of people who want to stay at an hotel, with a start and end time, find the minimum number of rooms
//needed to accomodate everyone
//Solution: We can use a priority queue, and store the end times of the person who are currently staying.
//For each person, we try assigning the room for which its occupant left the earliest, or we assign a new room.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> tasks(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tasks[i] = { a, b, i };
    }

    sort(tasks.begin(), tasks.end());

    int total = 0, curr = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        int f, s, idx;
        tie(f, s, idx) = tasks[i];
        if (pq.empty()) {
            curr++;
            pq.push({ s, curr });
            ans[idx] = curr;
        } else {
            auto min = pq.top();
            if (min.first < f) {
                pq.pop();
                pq.push({ s, min.second });
                ans[idx] = min.second;
            } else {
                curr++;
                pq.push({ s, curr });
                ans[idx] = curr;
            }
        }

        total = max(total, (int)pq.size());
    }

    cout << total << '\n';
    for (auto a : ans)
        cout << a << ' ';
    cout << '\n';
}