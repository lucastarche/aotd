//Movie Festival 2
//Problem: Same as Movie Festival 1, but now we have k club members, who can each of them watch a movie at the same time
//Solution: We use the same sorting criteria, but now we also keep a multiset with the endtime of each of the club members.
//Then, for each movie, we try finding if there is a club member who finishes before the current movie starts.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
        cin >> movies[i].second >> movies[i].first;

    sort(movies.begin(), movies.end());

    multiset<int> endings;
    for (int i = 0; i < k; i++)
        endings.insert(0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = endings.upper_bound(movies[i].second);
        if (it == endings.begin())
            continue;
        endings.erase(--it);
        endings.insert(movies[i].first);
        ans++;
    }

    cout << ans << '\n';
}