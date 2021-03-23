//PE 28: Number Spiral Diagonals
//Problem: Find the sum of the diagonals in the clockwise spiral of size 1001x1001
//Solution: We can see a pattern for each "layer" of the spiral, in that the numbers are
//lastSquare + (i - 1), lastSquare + 2 * (i - 1), lastSquare + 3 * (i - 1), and lastSquare + 4 * (i - 1).
//Then we just code it up and add all these numbers together.
//Runtime: O(n), where n is the length of the grid (in this case, 1001)
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 1LL;
    for (long long i = 3; i <= 1001; i += 2) {
        long long lastSquare = (i - 2) * (i - 2);
        long long curr = lastSquare + (i - 2) + 1;
        for (long long k = 1; k <= 4; k++) {
            ans += curr;
            curr += (i - 2) + 1;
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}