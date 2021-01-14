//Flood Fill
//Determines the connected area of a certain colour in a matrix, and paints it in another colour.
//It can be seen in painting programs, as the "bucket" tool.
//This is a recursive implementation, but we can also implement it with a stack or a queue.
//Runtime: O(n * m)
#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void FloodFill(vector<vector<char>> &mat, char target, char replacement, int x, int y) {
    int n = (int)mat.size();
    int m = (int)mat[0].size();

    if (mat[x][y] == replacement) return;
    else if (mat[x][y] != target) return;
    else mat[x][y] = replacement;

    for (int i = 0; i < (int)dx.size(); i++) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a < 0 || b < 0) return;
        if (a >= n || b >= m) return;
        FloodFill(mat, target, replacement, a, b);
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
    cin >> target >> replacement >> x >> y;

    FloodFill(mat, target, replacement, x, y);
    for (auto line : mat) {
        for (auto c : line) {
            cout << c;
        }
        cout << '\n';
    }
}