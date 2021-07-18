//Flight Routes
//Problem: Given a directed weighted graph, find the k shortest paths from 1 to n. Assume there are always at least k paths
//Solution: We can tweak Dijkstra's algorithm to get the k shortest paths. The idea is that we visit a node at most k times,
//instead of a single time, that is, we insert into the priority queue the k shortest paths from 1 to i, for every i
//Then it is just a matter of finding the ones that end in n from the queue, which we sort and then print
//Note that since we visit each node at most k times, the runtime is equal to k Dijkstras, plus sorting the k paths
//Runtime: O(km + kn log n + k log k)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        long long w;
        cin >> from >> to >> w;
        adj[from].push_back({ to, w });
    }

    vector<int> count(n + 1, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, 1 });

    vector<long long> paths;

    while (!pq.empty() && count[n] < k) {
        auto curr = pq.top();
        pq.pop();
        count[curr.second]++;
        if (curr.second == n) {
            paths.push_back(curr.first);
        }

        if (count[curr.second] <= k) {
            for (auto a : adj[curr.second]) {
                pq.push({ a.second + curr.first, a.first });
            }
        }
    }

    sort(paths.begin(), paths.end());
    for (auto a : paths) {
        cout << a << ' ';
    }
    cout << '\n';
}