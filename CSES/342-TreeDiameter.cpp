//Tree Diameter
//Problem: Given a tree, find the length of the longest path between any two nodes, also known as the diameter of a tree
//Solution: We can use a Depth First Search to get the node furthest from a single node.
//The idea is that we run a DFS starting from any arbitrary node to get the node furthest from it,
//and after that we run a second DFS starting from the result the first one gave us, to get the diameter
//This works because the longest path starting from a node X has the length of either A-X or B-X, where A-B is a diameter,
//so running the first DFS will yield either A or B, and the second one will give us the opposite node.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

pair<int, int> DFS(const vector<vector<int>>& ady, int n, int parent) {
    int furthest = n, dist = 0;

    for (auto a : ady[n]) {
        if (a == parent)
            continue;

        auto ans = DFS(ady, a, n);
        if (ans.second > dist) {
            furthest = ans.first;
            dist = ans.second;
        }
    }

    return { furthest, dist + 1 };
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ady(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        ady[a].push_back(b);
        ady[b].push_back(a);
    }

    auto ans = DFS(ady, 1, -1);
    ans = DFS(ady, ans.first, -1);

    cout << ans.second - 1 << '\n';
}