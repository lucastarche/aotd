//PE 82: Path Sum: Three ways
//Problem: Given an 80x80 matrix, find the path with the smallest sum from the left side to the right one, if you can only go down, up, and right.
//Solution: This one can also be solved by using Dijkstra's algorithm in an implicit graph.
//We just need to add the up move, and the ability to start on any cell of the left side, and end on any cell in the right side.
//Runtime: O(n^2 log n)
#include "EulerUtils.hpp"

const long long INF = 1e17;

using point = pair<long long, long long>;
const vector<long long> dx = { 1, 0, -1 };
const vector<long long> dy = { 0, 1, 0 };

long long solve(const vector<vector<long long>>& mat) {
    int n = (int)mat.size(), m = (int)mat[0].size();
    vector<vector<long long>> dist(n, vector<long long>(m, INF));

    priority_queue<pair<long long, point>> q;
    for (int i = 0; i < n; i++) {
        dist[i][0] = 0;
        q.push({ 0, { i, 0 } });
    }

    set<point> processed;
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

    long long best = INF;
    for (int i = 0; i < n; i++) {
        best = min(best, mat[i][m - 1] + dist[i][m - 1]);
    }
    return best;
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