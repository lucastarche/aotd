//0-1 BFS
//This algorithm gives the shortest path from a node to all the others, in a graph where all the weigths are either 0 or 1, hence its name.
//It works similar to Dijkstra's, but is a bit faster, since it doesn't have a log factor.
//The main idea is having a pseudo priority queue. Since we only have two possible weights, we can push to the front when the weigth is the smaller of the two, and to the back when it is the greater.
//Runtime: O(n + m)
#include "GraphWAL.cpp"

const int INF = 1e9;

vector<int> BFS01(GraphWAL &g, int start) {
    int n = g.getSize();
    vector<int> dist(n + 1, INF);

    //A deque is a double-ended queue, that is, we can push and pop from both sides.
    deque<int> q;
    q.push_back(start);
    dist[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop_front();

        for (auto a : g.getNeighbours(curr)) {
            int w = a.first, node = a.second;
            if (dist[node] > dist[curr] + w) {
                dist[node] = dist[curr] + w;
                if (w == 0) q.push_front(node);
                else q.push_back(node);
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    GraphWAL graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph.addEdge(a, b, w);
    }

    int source;
    cin >> source;
    vector<int> ans = BFS01(graph, source);
    for (int i = 1; i <= n; i++) {
        if (ans[i] != INF) {
            cout << i << " is " << ans[i] << " away from " << source << '\n';
        }
        else cout << i << " is not reachable from " << source << '\n';
    }

}
