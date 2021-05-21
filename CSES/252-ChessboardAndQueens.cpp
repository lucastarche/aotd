//Chessboard and Queens
//Problem: Given an 8x8 chessboard with some squares reserved, find the number of ways to place eight queens such that
//none of them attack each other, and no queen is on a reserved square.
//Solution: We can mark the reserved squares as occupied, and thenuse recursive backtracking to solve the eight queen problem as usual
//Runtime: O(n!), where n is the size of the board
#include <bits/stdc++.h>

using namespace std;

int solve(array<array<bool, 8>, 8> board, int row) {
    if (row == 8)
        return 1;

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        if (board[row][i]) {
            array<array<bool, 8>, 8> copy = board;
            for (int a = 0; a < 8; a++) {
                copy[row][a] = false;
                copy[a][i] = false;
            }

            for (int a = 0; a < 8; a++) {
                if (row + a >= 8 || i + a >= 8)
                    break;
                copy[row + a][i + a] = false;
            }

            for (int a = 0; a < 8; a++) {
                if (row + a >= 8 || i - a < 0)
                    break;
                copy[row + a][i - a] = false;
            }

            ans += solve(copy, row + 1);
        }
    }

    return ans;
}

int main() {
    array<array<bool, 8>, 8> board;
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            board[i][j] = (s[j] == '.');
        }
    }

    cout << solve(board, 0) << '\n';
}