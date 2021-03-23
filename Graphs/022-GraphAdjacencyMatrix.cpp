//Graph: Adjacency Matrix
//A representation of a graph that uses a table or matrix to store whether two nodes are connected or not. It can be either a boolean if it is unweighed, or a number if it is weighed.
//We can add edges in O(1), and check direct connectivity in O(1). However, it wastes a lot of memory in sparse graphs. Also, getting all the neighbours of a node takes O(n).
#include <bits/stdc++.h>

using namespace std;

class GraphAM {
private:
    vector<vector<bool>> matrix;

public:
    GraphAM(int n) {
        matrix.resize(n + 1, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; i++)
            matrix[i][i] = true;
    }

    void addEdge(int a, int b) {
        matrix[a][b] = true;
        matrix[b][a] = true;
    }

    void addDirectedEdge(int from, int to) {
        matrix[from][to] = true;
    }

    bool connected(int from, int to) {
        return matrix[from][to];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    GraphAM graph(n);
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
        } else {
            cout << from << " is not connected to " << to << '\n';
        }
    }
}
