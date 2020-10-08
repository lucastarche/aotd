#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

class GraphWAM {
    private:
        vector<vector<int>> matrix;
        int size;
    public:
        GraphWAM(int n) {
            size = n;
            matrix.resize(n + 1, vector<int>(n + 1, INF));
            for (int i = 1; i <= n; i++) matrix[i][i] = 0;
        }

        void addEdge(int a, int b, int w) {
            matrix[a][b] = w;
            matrix[b][a] = w;
        }

        int getDistance(int a, int b) {
            return matrix[a][b];
        }

        int getSize() {
            return size;
        }
};
