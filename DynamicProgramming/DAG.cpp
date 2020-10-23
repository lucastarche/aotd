#include <bits/stdc++.h>

using namespace std;

class DAG {
    private:
        vector<vector<int>> ady;
        vector<int> indegree;
        int size;
    public:
        DAG(int n) {
            ady.resize(n + 1);
            indegree.resize(n + 1);
            size = n;
        }

        void addEdge(int from, int to) {
            ady[from].push_back(to);
            indegree[to]++;
        }

        int getSize() {
            return size;
        }

        vector<int> getNeighbours(int n) {
            return ady[n];
        }

        int getIndegree(int n) {
            return indegree[n];
        }
};
