//Tasks and Deadlines
//Problem: Given a list of tasks with a duration and a deadline, find the best reward we can get,
//if we define the reward as the difference between the deadline and when it was completed.
//Solution: We can sort the tasks in increasing order of duration, and then always do them in this order.
//This greedy solution works because we get better rewards if we do two tasks in one time block than doing one longer task.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    long long time = 0, reward = 0;
    for (auto& t : tasks) {
        time += t.first;
        reward += t.second - time;
    }

    cout << reward << '\n';
}