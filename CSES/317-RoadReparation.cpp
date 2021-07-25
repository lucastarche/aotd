//Road Reparation
//Problem: Given a weighted graph, find the cost of a minimum spanning tree, or report that there is none
//Solution: This problem can be easily solved with Kruskal's algorithm, which uses a Disjoint Union-Find Set
//Note that we need to sort the edges in increasing order, so our operator< is actually inverted
//Runtime: O(m log m + n * inverse_ackermann(n))
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    long long w;
    int from, to;
};

bool operator<(const Edge& a, const Edge& b) {
    return a.w > b.w;
}

int find(vector<int>& link, int x) {
    if (link[x] == x)
        return x;
    return (link[x] = find(link, link[x]));
}

void connect(vector<int>& link, int x, int y) {
    x = find(link, x), y = find(link, y);
    link[x] = y;
}

bool same(vector<int>& link, int a, int b) {
    return find(link, a) == find(link, b);
}

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<Edge> pq;
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.from >> e.to >> e.w;
        pq.push(e);
    }

    long long ans = 0;
    vector<int> link(n + 1);
    for (int i = 1; i <= n; i++)
        link[i] = i;

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();
        if (!same(link, curr.from, curr.to)) {
            connect(link, curr.from, curr.to);
            ans += curr.w;
        }
    }

    bool possible = true;
    int comp = find(link, 1);
    for (int i = 1; i <= n; i++)
        if (comp != find(link, i))
            possible = false;

    if (possible)
        cout << ans << '\n';
    else
        cout << "IMPOSSIBLE\n";
}