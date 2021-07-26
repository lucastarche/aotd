//Road Construction
//Problem: Given a graph with n nodes, and m days in which we add an edge, print for each day the number of components, and the size of the biggest component
//Solution: We can use a Disjoint Union-Find Set to keep track of the components and their sizes. Then we can update the previous day's solution in basically constant time,
//since we connect two nodes if they belong to different components, so we reduce by one the number of components, and the biggest will be the biggest yesterday or the component we just connected
//Runtime: O(m * inverse_ackermann(n))
#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& link, int x) {
    if (x == link[x])
        return x;
    return (x = find(link, link[x]));
}

void connect(vector<int>& link, vector<int>& size, int a, int b) {
    a = find(link, a), b = find(link, b);
    if (size[a] < size[b])
        swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    int amount = n, biggest = 1;
    vector<int> link(n + 1), size(n + 1, 1);
    for (int i = 1; i <= n; i++)
        link[i] = i;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from = find(link, from), to = find(link, to);
        if (from != to) {
            connect(link, size, from, to);
            amount--;
            biggest = max(biggest, max(size[from], size[to]));
        }
        cout << amount << ' ' << biggest << '\n';
    }
}
