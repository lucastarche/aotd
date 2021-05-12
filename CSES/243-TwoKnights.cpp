//Two Knights
//Problem: Given a number n, print the number of ways two horses can be placed in a chessboard of size 1x1, 2x2 ... nxn,
//such that the horses do not attack each other.
//Solution: We can hardcode the small cases (n < 4), and then simply note five different types of squares in the board:
//the ones where you attack 2, 3, 4, 6 or 8 other squares. All of these can be calculated in O(1) time, so the problem is closed formula.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long result = 0;
        if (i == 1)
            cout << 0 << '\n';
        else if (i == 2)
            cout << 6 << '\n';
        else if (i == 3)
            cout << 28 << '\n';
        else {
            long long attack2 = 4; //4 corners.
            long long attack3 = 8; //8 squares next to corners.
            long long attack4 = 4 * i - 12;
            long long attack6 = 4 * i - 16;
            long long attack8 = (i - 4) * (i - 4);
            result += attack2 * (i * i - 3);
            result += attack3 * (i * i - 4);
            result += attack4 * (i * i - 5);
            result += attack6 * (i * i - 7);
            result += attack8 * (i * i - 9);
            result /= 2; //Order of the horses doesnt matter.
            cout << result << "\n";
        }
    }
}