//Union Find
//A data structure useful for algorithms like Kruskal, which finds the minimum or maximum spanning tree of a graph
//same() works in O(1), and this implementation of find() and unite work in O(inverse_ackerman(n)) (almost O(1))
#include <bits/stdc++.h>

using namespace std;

class UnionFind {
    private:
        vector<int> size;
        vector<int> link;

    public:
        UnionFind(int n) {
            size.resize(n + 1, 1);
            link.resize(n + 1, 1);
            for (int i = 1; i <= n; i++) link[i] = i;
        }

        int find(int x) {
            if (x == link[x]) return x;
            return link[x] = find(link[x]);
        }

        bool same(int a, int b) {
            return find(a) == find(b);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (size[a] < size[b]) swap(a, b);
            size[a] += size[b];
            link[b] = a;
        }

        int getSize(int n) {
            return size[find(n)];
        }
};

int main() {
    int n;
    cin >> n;
    UnionFind uf(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    int q;
    cin >> q;
    cout << uf.getSize(q) << '\n';
}
