//0-1 Knapsack
//Problem: We are given an array of objects, each with a weigth and value, and a knapsack, in which we can fit a certain weigth at most. Determine the maximum value we can carry in the knapsack.
//One of the classical 2D DP problems. The base cases are when we run out of items or weigth, in which the value is 0.
//The name is due to the fact that, for each item, we can choose to either leave it (0) or take it (1).
//Runtime: O(nw) with bottom-up. This can be improved drastically with top-down, given that we only visit the reachable states.
#include <bits/stdc++.h>

using namespace std;

int Knapsack(vector<pair<int, int>> &objects, int w) {
    int n = (int)objects.size();
    vector<vector<int>> value(n + 1, vector<int>(w + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) continue;
            if (objects[i - 1].first > j) value[i][j] = value[i - 1][j];
            else value[i][j] = max(
                value[i - 1][j - objects[i - 1].first] + objects[i - 1].second,
                value[i - 1][j]
            );
        }
    }

    return value[n][w];
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> obj(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        obj[i] = {a, b};
    }

    cout << "The max possible value is " << Knapsack(obj, w) << '\n';
}
