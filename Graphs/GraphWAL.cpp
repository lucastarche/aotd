//Note: This is a copy of aotd#23, but without defining main() to use it in other files.
#include <bits/stdc++.h>

using namespace std;

class GraphWAL {
private:
    vector<vector<pair<int, int>>> ady;
    int size;

public:
    GraphWAL(int n) {
        ady.resize(n + 1);
        size = n;
    }

    void addEdge(int a, int b, int w) {
        ady[a].push_back({ w, b });
        ady[b].push_back({ w, a });
    }

    bool connected(int from, int to) {
        for (auto a : ady[from]) {
            if (a.second == to)
                return true;
        }
        return false;
    }

    int getSize() {
        return size;
    }

    vector<pair<int, int>> getNeighbours(int n) {
        return ady[n];
    }
};
