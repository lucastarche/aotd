//Range Sum Query 2D
//Given the points (x1, y1), (x2, y2), we can calculate the sum of the subrectangle (x1, y1) to (x2, y2) in O(1) if we know the values for:
//(0, 0) to (x1 - 1, y1 - 1): "A"
//(0, 0) to (x1 - 1, y2 - 1): "B"
//(0, 0) to (x2 - 1, y1 - 1): "C"
//(0, 0) to (x2, y2): "D"
//Then, we can get the rectangle by using the formula: sum = D - B - C + A
//Runtime: O(1) after O(n^2) preprocessing
#include <bits/stdc++.h>

using namespace std;

class RangeSum2D {
private:
    vector<vector<int>> mat;

public:
    RangeSum2D(const vector<vector<int>>& in) {
        int N = (int)in.size();
        int M = (int)in[0].size();
        mat.resize(N, vector<int>(M));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                mat[i][j] = query(i - 1, j) + query(i, j - 1) - query(i - 1, j - 1) + in[i][j];
            }
        }
    }

    int query(int x1, int y1) {
        if (x1 < 0 || y1 < 0)
            return 0;
        return mat[x1][y1];
    }

    int query(int x1, int y1, int x2, int y2) {
        int A = query(x1 - 1, y1 - 1);
        int B = query(x1 - 1, y2 - 1);
        int C = query(x2 - 1, y1 - 1);
        int D = query(x2, y2);
        return D - C - B + A;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> in(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> in[i][j];

    RangeSum2D mat = RangeSum2D(in);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << mat.query(x1, y1, x2, y2) << '\n';
    }
}
