#include <bits/stdc++.h>

using namespace std;

class GraphWEL {
    private:
        vector<tuple<int, int, int>> edges;
        int size;
    public:
        GraphWEL(int n) {
            size = n;
        }

        void addEdge(int a, int b, int w) {
            edges.push_back(
                make_tuple(w, a, b)
            );
        }

        int getSize() {
            return size;
        }

        vector<tuple<int, int, int>> getEdges() {
            return edges;
        }
};
