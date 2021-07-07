//Labyrinth
//Problem: Given a maze and two points, A and B, find a path from A to B
//Solution: We can use BFS over the maze, since we have a defined start and end.
//For this we know the edges (up, down, left and right), as well as the nodes, which are the coordinates in the maze.
//Note that we also have to keep track of the parent, that is, the node from where we first discovered the node
//Then, to print the path, we simply start in the end, and traverse through all the parents until we get to the start
//Runtime: O(n * m)
#include <bits/stdc++.h>

using namespace std;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };
const char dir[] = { 'U', 'L', 'R', 'D' };

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> start, end;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'A') {
                start = { i, j };
                maze[i][j] = '.';
            } else if (maze[i][j] == 'B') {
                end = { i, j };
                maze[i][j] = '.';
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<vector<int>> parent(n, vector<int>(m));
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || y < 0 || x >= n || y >= m || dist[x][y] < INF || maze[x][y] == '#')
                continue;
            dist[x][y] = dist[i][j] + 1;
            parent[x][y] = k;
            q.push({ x, y });
        }
    }

    if (dist[end.first][end.second] == INF) {
        cout << "NO\n";
    } else {
        cout << "YES\n"
             << dist[end.first][end.second] << '\n';

        string path = "";
        auto curr = end;
        while (curr != start) {
            int k = parent[curr.first][curr.second];
            path += dir[k];
            curr = {
                curr.first - dx[k],
                curr.second - dy[k]
            };
        }

        reverse(path.begin(), path.end());
        cout << path << '\n';
    }
}