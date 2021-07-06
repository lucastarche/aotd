//Counting Rooms
//Problem: We have a map of a building, where each part is either # (wall) or . (empty). Count the number of rooms
//Solution: We can use flood fill to mark where each room is. For each empty space, we flood fill the entire room with walls
//This guarantees that each component (aka room) will be visited only once
//Runtime: O(n^2), since each coordinate is visited at most once
#include <bits/stdc++.h>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void floodFill(vector<vector<char>>& building, int i, int j) {
    int n = (int)building.size(), m = (int)building[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || building[i][j] == '#')
        return;
    building[i][j] = '#';
    for (int k = 0; k < 4; k++) {
        floodFill(building, i + dx[k], j + dy[k]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> building(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> building[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (building[i][j] == '#')
                continue;
            ans++;
            floodFill(building, i, j);
        }
    }

    cout << ans << '\n';
}