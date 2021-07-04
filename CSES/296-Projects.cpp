//Projects
//Problem: Given a list of projects, each of which has a start, end and reward, we want to maximize the reward if we can assist to one project per day at most
//Solution: First and foremost, note that n is much smaller than the start and end times, so we can use coordinate compression, since we have at most 2n interesting times
//After this, we sort the projects according to their end times, and with a DP table we will store the maximum value we can get in the first i interesting days
//Then we simply try maximizing the current day by binary searching all the projects that end in the current day
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

struct Project {
    int start, end;
    long long reward;
};

int main() {
    int n;
    cin >> n;

    vector<int> times = { 0 };
    vector<Project> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
        times.push_back(projects[i].start);
        times.push_back(projects[i].end);
    }

    sort(times.begin(), times.end());
    auto end = unique(times.begin(), times.end());
    times.erase(end, times.end());

    for (int i = 0; i < n; i++) {
        projects[i].start = lower_bound(times.begin(), times.end(), projects[i].start) - times.begin();
        projects[i].end = lower_bound(times.begin(), times.end(), projects[i].end) - times.begin();
    }

    auto comp = [](const Project& lhs, const Project& rhs) -> bool {
        return lhs.end < rhs.end;
    };

    int k = (int)times.size() + 1;
    vector<long long> dp(k, 0);
    sort(projects.begin(), projects.end(), comp);

    for (int i = 1; i < k; i++) {
        dp[i] = dp[i - 1];

        int start = lower_bound(projects.begin(), projects.end(), Project({ 0, i, 0 }), comp) - projects.begin();
        if (projects[start].end != i)
            continue;
        for (int j = start; j < n && projects[start].end == projects[j].end; j++) {
            dp[i] = max(dp[i], dp[projects[j].start - 1] + projects[j].reward);
        }
    }

    cout << dp[k - 1] << '\n';
}