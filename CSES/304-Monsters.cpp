//Monsters
//Problem: Given a maze, we want to find whether there is a path to one of the borders, avoiding the monsters spread around the maze, which may move optimally according to your path
//Both you and the monsters move at one square per second. Determine if there is a path, and if so, print a possibility
//Solution: We know that we can escape the maze if there is at least an exit to which we are closer than any monster
//For this, we can run two BFS: the first is a multi-source BFS, starting for every monster. This gives us the distance to the closest monster, and works similar to regular BFS
//The idea is that we have k different sources instead of one, which we push into the queue at the start, all with distance zero.
//Then we run a second BFS from the player position, keeping track of the parents for path reconstruction
//Finally we check if there is a border such that we are closer than any monster.
//If there is, we report it and reconstruct the path
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };
const char dir[] = { 'U', 'L', 'R', 'D' };

void BFS(const vector<vector<char>>& maze, vector<vector<int>>& dist, vector<vector<int>>& parent, queue<pair<int, int>>& q, bool changeParent) {
    int n = maze.size(), m = maze[0].size();
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int i = p.first, j = p.second;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == '#')
                continue;
            if (dist[x][y] > dist[i][j] + 1) {
                dist[x][y] = dist[i][j] + 1;
                if (changeParent)
                    parent[x][y] = k;
                q.push({ x, y });
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> start;
    queue<pair<int, int>> q;
    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<int>> parent(n, vector<int>(m, -1));
    vector<vector<int>> startDist(n, vector<int>(m, INF));
    vector<vector<int>> monsterDist(n, vector<int>(m, INF));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'M') {
                q.push({ i, j });
                monsterDist[i][j] = 0;
            } else if (maze[i][j] == 'A') {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    cout << "YES\n";
                    return 0;
                }
                start = { i, j };
                startDist[i][j] = 0;
            }
        }
    }

    BFS(maze, monsterDist, parent, q, false);
    q.push(start);
    BFS(maze, startDist, parent, q, true);

    pair<int, int> exit = { -1, -1 };
    for (int i = 0; i < n; i++) {
        if (maze[i][0] == '.' && startDist[i][0] < monsterDist[i][0]) {
            exit = { i, 0 };
        } else if (maze[i][m - 1] == '.' && startDist[i][m - 1] < monsterDist[i][m - 1]) {
            exit = { i, m - 1 };
        }
    }

    for (int j = 0; j < m; j++) {
        if (maze[0][j] == '.' && startDist[0][j] < monsterDist[0][j]) {
            exit = { 0, j };
        } else if (maze[n - 1][j] == '.' && startDist[n - 1][j] < monsterDist[n - 1][j]) {
            exit = { n - 1, j };
        }
    }

    if (exit == make_pair(-1, -1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n"
             << startDist[exit.first][exit.second] << '\n';

        stack<char> ans;
        int i = exit.first, j = exit.second;
        while (parent[i][j] != -1) {
            int k = parent[i][j];
            ans.push(dir[k]);
            i -= dx[k];
            j -= dy[k];
        }

        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
        cout << '\n';
    }
}