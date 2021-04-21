//PE 86: Cuboid Route
//Problem: Given an AxBxC cuboid, there are up to three shortest paths such that we walk on the sides of the cuboid exclusively.
//Find the value of M such that the sum of cuboids of up to MxMxM with an integer shortest path is greater than one million.
//Solution: We can prove that if a <= b <= c, then the shortest path will be sqrt(a^2 + (b + c)^2) units long (can be seen by "unwrapping" the cuboid)
//Then, we can use Dynamic Programming to compute the number of solutions efficiently
//Runtime: O(n^2)
#include "EulerUtils.hpp"

long long solve() {
    vector<long long> dp(10000, 0);
    for (long long a = 2; a < 10000; a++) {
        dp[a] = dp[a - 1];
        for (long long bc = 3; bc <= 2 * a; bc++) {
            long long sqroot = floor(sqrt(a * a + bc * bc));
            if (sqroot * sqroot == a * a + bc * bc) {
                if (bc <= a) {
                    dp[a] += floor(bc / 2);
                } else {
                    dp[a] += 1 + (a - floor((bc + 1) / 2));
                }
            }
        }

        if (dp[a] > 1000000)
            return a;
    }

    return 0;
}

int main() {
    cout << solve() << '\n';
}