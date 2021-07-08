//Building Roads
//Problem: Given a list of cities, and a list of roads, find the minimum number of roads you need to build so you can reach every city.
//Solution: We can use a union-find data structure to keep track of which cities are connected to each other.
//Then, for each city that is not connected to city 1, we add a road and update the union-find data structure.
//This will give us the minimum, since we have a graph split into k components, and it suffices to connect each component to the first one.
//Runtime: O(n * inverse_ackermann(n))
#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& link, int x) {
    if (link[x] == x)
        return x;
    return link[x] = find(link, link[x]);
}

bool join(vector<int>& link, int a, int b) {
    a = find(link, a);
    b = find(link, b);
    if (a == b)
        return false;
    link[a] = b;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> link(n + 1, 0);
    for (int i = 1; i <= n; i++)
        link[i] = i;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        join(link, from, to);
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        int a = find(link, i), b = find(link, 1);
        if (a != b) {
            join(link, 1, i);
            ans.push_back({ a, b });
        }
    }

    cout << (int)ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}