//Note: This is a copy of aotd#23, but without defining main() to use it in other files.
#include <bits/stdc++.h>

using namespace std;

class GraphAL {
private:
    vector<vector<int>> ady;
    int size;

public:
    GraphAL(int n) {
        ady.resize(n + 1);
        size = n;
    }

    void addEdge(int a, int b) {
        ady[a].push_back(b);
        ady[b].push_back(a);
    }

    void addDirectedEdge(int from, int to) {
        ady[from].push_back(to);
    }

    bool connected(int from, int to) {
        for (auto a : ady[from]) {
            if (a == to)
                return true;
        }
        return false;
    }

    int getSize() {
        return size;
    }

    vector<int> getNeighbours(int n) {
        return ady[n];
    }
};
