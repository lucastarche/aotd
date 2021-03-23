//Edit Distance (DP version)
//It is the same as yesterday's, but infitely more efficient. The idea is that, if we process the values in order from the top-left to the bottom-right, we don't need to do any recursion, since we already processed all the values to calculate dist[i][j].
//The runtime is, as stated yesterday, O(nm), which is way better than the O(3^n) from yesterday.
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int EditDistanceDP(string& a, string& b) {
    int n = (int)a.size();
    int m = (int)b.size();
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, INF));
    dist[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dist[i][0] = i;
    }

    for (int j = 1; j <= m; j++) {
        dist[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = min(
                                 dist[i - 1][j],
                                 dist[i][j - 1],
                                 dist[i - 1][j - 1])
                    + 1;
            }
        }
    }

    return dist[n][m];
}

int main() {
    string a, b;
    cin >> a >> b;
    int ans = EditDistanceDP(a, b);
    cout << "The edit distance from " << a << " to " << b << " is " << ans << '\n';
}
