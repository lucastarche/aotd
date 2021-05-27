//Movie Festival
//Problem: Given a list of movies with start and end time, find the maximum number of movies you can assist entirely
//Solution: We can sort the movies by their end times, and then always watching the first movie we can.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](auto& lhs, auto& rhs) -> bool {
        return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second < rhs.second;
    });

    int last = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].first >= last) {
            last = movies[i].second;
            curr++;
        }
    }

    cout << curr << '\n';
}