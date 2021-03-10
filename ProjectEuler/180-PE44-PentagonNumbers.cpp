//PE 44: Pentagon Numbers
//Problem: We define the sequence of pentagonal numbers by the formula P_n = n * (3 * n - 1) / 2. Find the pair of pentagonal numbers P_i and P_j, such that P_i + P_j is pentagonal, D = |P_i - P_j| is pentagonal, and D is minimised. Return such D.
//Solution: We can build a large enough set of pentagonal numbers (4000 are more than enough in this case), and then iterate through each possible pair.
//The answer is the minimum of the pairs where both conditions hold.
//Runtime: O(n^2 log n), where n is the amount of pentagonal numbers we generate.
#include "EulerUtils.hpp"

long long solve() {
    set<long long> pentagonals;
    for (long long i = 1LL; i <= 4000LL; i++) {
        pentagonals.insert((i * (3 * i - 1)) / 2);
    }

    long long ans = 10000000000LL;
    for (auto n : pentagonals) {
        for (auto m : pentagonals) {
            if (pentagonals.count(n + m) > 0 && pentagonals.count(abs(n - m)) > 0) {
                ans = min(ans, abs(n - m));
            }
        }
    }
    
    return ans;
}

int main() {
    cout << solve() << '\n';
}
