//Flood Fill with Queue
//Same as yesterday, but we maintain a queue with future nodes to be visited instead of using recursion.
//This has the benefit that we reduce the overhead generated by recursion.
//Note that we do not need to pass the "target" parameter, because we can just define it before running the loop.
//Runtime: O(n * m)
#include <bits/stdc++.h>

using namespace std;

vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };

void FloodFill(vector<vector<char>>& mat, char replacement, int x, int y) {
    int n = (int)mat.size();
    int m = (int)mat[0].size();
    char target = mat[x][y];

    queue<pair<int, int>> q;
    q.push({ x, y });
    mat[x][y] = replacement;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < (int)dx.size(); i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || b < 0)
                continue;
            else if (a >= n || b >= m)
                continue;
            else if (mat[a][b] == replacement)
                continue;
            else if (mat[a][b] == target)
                continue;
            else {
                mat[a][b] = replacement;
                q.push({ a, b });
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    char target, replacement;
    int x, y;
    cin >> replacement >> x >> y;

    FloodFill(mat, replacement, x, y);
    for (auto line : mat) {
        for (auto c : line) {
            cout << c;
        }
        cout << '\n';
    }
}