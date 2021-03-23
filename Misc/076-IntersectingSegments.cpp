//Intersecting Segments
//Given a list of start and end points, we have to find the maximum amount of segments that intersect in a point in the number line.
//One idea is to add one to a counter every time a segment starts, and decrease the counter by one every time a segment ends. Then, we can sort these events and find the maximum.
//Runtime: O(n log n)
//Note 1: if two segments only share one point, we do not consider them to intersect. That is: given segments (0, 1) and (1, 2), the answer would be 1 instead of 2.
//Note 2: given that 'E' < 'S', this restriction will be applied automatically. Using characters with inverse order will lead to the problem described in Note 1.
#include <bits/stdc++.h>

using namespace std;

int IntersectingSegments(const vector<pair<int, int>>& segments) {

    vector<pair<int, char>> events;
    for (int i = 0; i < (int)segments.size(); i++) {
        events.push_back({ segments[i].first, 'S' });
        events.push_back({ segments[i].second, 'E' });
    }

    sort(events.begin(), events.end());
    int n = (int)events.size();

    int counter = 0, maxVal = 0;
    for (int i = 0; i < n; i++) {
        if (events[i].second == 'S') {
            counter++;
            maxVal = max(maxVal, counter);
        } else {
            counter--;
        }
    }

    return maxVal;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    int ans = IntersectingSegments(arr);

    cout << "The maximum amount of intersecting segments is: " << ans << '\n';
}