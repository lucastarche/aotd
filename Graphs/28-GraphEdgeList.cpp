//Graph: Edge List
//The most basic representation, just a list of edges, which can be weighed or not.
//We can add edges in O(1), and it is very space efficient.
//However, checking direct connectivity and getting all neighbours of a node both take O(m), where m is the amount of edges in the graph.
//This representation is often used for the input of the graph, or for a couple of algorithms, like Bellman-Ford's algorithm, and Kruskal's algorithm.
#include <bits/stdc++.h>

using namespace std;

class GraphEL {
    private:
        vector<pair<int, int>> edges;
    public:
        GraphEL(int n) {
            edges.resize(n + 1);
        }

        void addEdge(int a, int b) {
            edges.push_back({a, b});
        }

        bool connected(int from, int to) {
            for (auto e : edges) {
                if (e == make_pair(from, to) || e == make_pair(to, from)) {
                    return true;
                }
            }
            return false;
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    GraphEL graph(n);
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
