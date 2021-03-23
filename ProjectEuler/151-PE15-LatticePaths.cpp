//PE 15: Lattice Paths
//Problem: Given a 20x20 grid, find the number of ways one can get from (0, 0) to (20, 20) by only going down or right.
//Solution: We can solve this problem with a DP algorithm, such as the one seen in AOTD#41.
//In short, we set the base cases where either of the coordinates is 0, and then we can get every other cell by adding the one above and the one to the left.
//Runtime: O(n^2)
//Note: There is also a O(n) solution using combinatronics (which is the one I initially used when solving this problem), but it requires temporally storing
//integers greater than long long (~1e18).
#include "EulerUtils.hpp"

long long solve() {
    vector<vector<long long>> ways(21, vector<int>(21, 0LL));
    ways[0][0] = 1LL;
    for (int i = 1; i <= 20; i++)
        ways[i][0] = 1LL;
    for (int j = 1; j <= 20; j++)
        ways[0][j] = 1LL;

    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= 20; j++)
            ways[i][j] = ways[i - 1][j] + ways[i][j - 1];

    return ways[20][20];
}

int main() {
    cout << solve() << '\n';
}
