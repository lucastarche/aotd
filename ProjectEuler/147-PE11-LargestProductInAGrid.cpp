//PE 11: Largest Product in a grid
//Problem: Given a 20x20 grid, find the greatest product of 4 adjacent numbers in the same direction (including diagonals).
//Solution: We can simply test every possible direction, given that the sizes are small.
//Runtime: O(n^2 * m), where n^2 is the size of the grid, and m is the amount of adjacent numbers.
#include "EulerUtils.hpp"

long long solve(vector<vector<long long>> grid) {
    long long ans = 0LL;
    //Horizontal
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < (20 - 4); j++) {
            long long product = 1LL;
            for (int k = j; k < j + 4; k++) product *= grid[i][k];
            ans = max(ans, product);
        }
    }

    //Vertical
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < (20 - 4); i++) {
            long long product = 1LL;
            for (int k = i; k < i + 4; k++) product *= grid[k][i];
            ans = max(ans, product);
        }
    }

    //Right diagonal
    for (int i = 0; i < (20 - 4); i++) {
        for (int j = 0; j < (20 - 4); j++) {
            long long product = 1LL;
            for (int k = 0; k < 4; k++) product *= grid[i + k][j + k];
            ans = max(ans, product);
        }
    }

    //Left diagonal
    for (int i = 0; i < (20 - 4); i++) {
        for (int j = 0; j < (20 - 4); j++) {
            long long product = 1LL;
            for (int k = 0; k < 4; k++) product *= grid[i + k][j + (4 - k)];
            ans = max(ans, product);
        }
    }

    return ans;
}

int main() {
    ifstream in("input-011.txt");
    vector<vector<long long>> grid(20, vector<long long>(20, 0LL));
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            in >> grid[i][j];
        }
    }

    cout << solve(grid) << '\n';
}