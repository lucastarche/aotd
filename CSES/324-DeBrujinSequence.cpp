//De Brujin Sequence
//Problem: Given an integer n <= 15, find a minimum lenght bit string such that every possible bit string of n digits is contained in it
//Solution: We can represent this problem as an eulerian path that visits each edge exactly once, in a graph whose nodes are all possible bitstrings of length n-1,
//and the edges represent shifting a 1 or 0 from the right. After this, we find the path using Hierholzer's algorithm for a directed graph,
//and print the start node, appended all the values represented in the edges, in the order we visit them.
//Runtime: O(2^n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    if (n == 1) {
        cout << "01\n";
        return 0;
    }
    k = 1 << (n - 1);

    vector<int> outdegree(k, 2);
    vector<vector<int>> adj(k);
    int mask = k - 1;
    for (int i = 0; i < k; i++) {
        adj[i].push_back((i << 1) & mask);
        adj[i].push_back(((i << 1) + 1) & mask);
    }

    int curr = 0;
    stack<int> path;
    vector<int> circuit;
    path.push(0);

    while (!path.empty()) {
        if (outdegree[curr]) {
            path.push(curr);
            int next = adj[curr].back();
            adj[curr].pop_back();
            outdegree[curr]--;
            curr = next;
        } else {
            circuit.push_back(curr);
            curr = path.top();
            path.pop();
        }
    }

    reverse(circuit.begin(), circuit.end());

    string ans;
    for (int i = 0; i < n - 1; i++)
        ans += '0';

    for (int i = 0; i < (int)circuit.size() - 1; i++) {
        ans += '0' + (circuit[i + 1] & 1);
    }

    cout << ans << '\n';
}