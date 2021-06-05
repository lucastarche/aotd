//Traffic Lights
//Problem: Given a series of traffic lights that are added on each turn, find the longest segment on a street of lenght x
//delimited by two traffic lights, or the start/end of the street.
//Solution: We can use a set with the traffic lights we currently have, so as to find the one lower and greater than the current one.
//We also need a multiset to store the segment distances efficiently.
//After this, it is just a matter of fact of updating the sets accordingly, and printing the max in the multiset.
//Note: Due to the big input size in this problem, we need to use fast I/O (first three lines)
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> x >> n;

    set<int> lights;
    multiset<int> distances;
    distances.insert(x);
    lights.insert(x);
    lights.insert(0);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        auto right = lights.lower_bound(k);
        auto left = --right;
        right++;

        int leftVal = *left;
        int rightVal = *right;

        int leftDist = k - leftVal;
        int rightDist = rightVal - k;
        int dist = rightVal - leftVal;

        auto iter = distances.find(dist);
        distances.erase(iter);
        distances.insert(leftDist);
        distances.insert(rightDist);

        cout << *distances.rbegin() << ' ';
        lights.insert(k);
    }

    cout << '\n';
}