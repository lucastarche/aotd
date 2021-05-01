//PE 96: Sudoku
//Problem: Find the sum of the first three digit of every provided sudoku.
//Solution: We can solve each puzzle by using recursive backtracking. For each unsolved digit, we recursively try
//that digit until the puzzle is solved. Luckly there aren't any extremely hard ones, given that this method grows
//exponentially slower as the number of clues gets lower.
//Runtime: O(k * 9^n), where k is the number of puzzles.
#include "EulerUtils.hpp"

bool solve(array<array<int, 9>, 9>& state) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (state[i][j] != 0)
                continue;

            bitset<10> possible;
            possible.set();
            possible.set(0, false);

            for (int k = 0; k < 9; k++) {
                if (state[i][k] != 0)
                    possible.set(state[i][k], false);
                if (state[k][j] != 0)
                    possible.set(state[k][j], false);
            }

            int r1 = (i / 3) * 3;
            int r2 = (j / 3) * 3;

            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    if (state[a + r1][b + r2] != 0) {
                        possible.set(state[a + r1][b + r2], false);
                    }
                }
            }

            if (possible.none())
                return false;
            for (int k = 1; k <= 9; k++) {
                if (possible.test(k)) {
                    state[i][j] = k;
                    if (solve(state)) {
                        return true;
                    }
                    state[i][j] = 0;
                }
            }

            return false;
        }
    }

    return true;
}

long long solve(const vector<array<array<int, 9>, 9>>& grids) {
    long long ans = 0LL;
    for (auto a : grids) {
        solve(a);
        ans += a[0][0] * 100 + a[0][1] * 10 + a[0][2];
    }

    return ans;
}

int main() {
    ifstream in("input-096.txt");
    vector<array<array<int, 9>, 9>> grids(50);
    for (int i = 0; i < 50; i++) {
        string temp;
        getline(in, temp);
        for (int j = 0; j < 9; j++) {
            getline(in, temp);
            for (int k = 0; k < 9; k++) {
                grids[i][j][k] = temp[k] - '0';
            }
        }
    }

    cout << solve(grids) << '\n';
}