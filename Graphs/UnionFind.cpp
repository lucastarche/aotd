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
