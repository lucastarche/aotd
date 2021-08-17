//Subordinates
//Problem: Given a rooted tree on node 1, count the number of children (direct or indirect) in its subtree
//Solution: We can use recursion for this, since the number of children is just the size of the subtree minus the root
//Since we visit each node at most once, it will run in linear time
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int countSubordinates(const vector<vector<int>>& adj, vector<int>& amount, int curr) {
    for (auto a : adj[curr])
        amount[curr] += countSubordinates(adj, amount, a) + 1;
    return amount[curr];
}

int main() {
    int n;
    cin >> n;
    vector<int> amount(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int j;
        cin >> j;
        adj[j].push_back(i);
    }

    countSubordinates(adj, amount, 1);
    for (int i = 1; i <= n; i++)
        cout << amount[i] << ' ';
    cout << '\n';
}