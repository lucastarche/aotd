//Graph: Adjacency List
//A representation of a graph that uses a list of dynamic arays, to check if there is an edge between two nodes or not. We can add a pair instead of an int to make the graph weighed.
//We can add edges in O(1), and check direct conectivity in O(m). Listing all neighbours of a node takes just O(m) time, where m is the amount of neighbours.
#include <bits/stdc++.h>

using namespace std;

class GraphAL {
    private:
        vector<vector<int>> ady;
    public:
        GraphAL(int n) {
            ady.resize(n + 1);
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
                if (a == to) return true;
            }
            return false;
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    GraphAL graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int from, to;
        cin >> from >> to;
        if (graph.connected(from, to)) {
            cout << from << " is connected to " << to << '\n';
        }
        else {
            cout << from << " is not connected to " << to << '\n';
        }
    }
}
