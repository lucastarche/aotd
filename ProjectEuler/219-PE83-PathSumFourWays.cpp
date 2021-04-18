//PE 83: Path Sum: Four ways
//Problem: Given an 80x80 matrix, find the path with the smallest sum from the top left to the bottom right.
//Solution: This one can also be solved by using Dijkstra's algorithm in an implicit graph.
//Just remember to modify dx and dy yet again to add the possibility to move up, down, left and right.
//Runtime: O(n^2 log n)
#include "EulerUtils.hpp"

const long long INF = 1e17;

using point = pair<long long, long long>;
const vector<long long> dx = { 1, 0, -1, 0 };
const vector<long long> dy = { 0, 1, 0, -1 };

long long solve(const vector<vector<long long>>& mat) {
    int n = (int)mat.size(), m = (int)mat[0].size();
    vector<vector<long long>> dist(n, vector<long long>(m, INF));
    dist[0][0] = 0;

    priority_queue<pair<long long, point>> q;
    set<point> processed;
    q.push({ 0, { 0, 0 } });

    while (!q.empty()) {
        point curr = q.top().second;
        q.pop();
        if (processed.count(curr) > 0)
            continue;
        processed.insert(curr);

        long long x = curr.first, y = curr.second;
        for (int i = 0; i < (int)dx.size(); i++) {
            long long nx = curr.first + dx[i], ny = curr.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (dist[x][y] + mat[x][y] < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + mat[x][y];
                q.push({ -dist[nx][ny], { nx, ny } });
            }
        }
    }

    return dist[n - 1][m - 1] + mat[n - 1][m - 1];
}

int main() {
    ifstream in("input-081.txt");
    vector<vector<long long>> mat(80, vector<long long>(80, 0));
    for (int i = 0; i < 80; i++) {
        string line;
        getline(in, line);

        stringstream linestream(line);
        for (int j = 0; j < 80; j++) {
            string curr;
            getline(linestream, curr, ',');
            mat[i][j] = stoll(curr);
        }
    }

    cout << solve(mat) << '\n';
}