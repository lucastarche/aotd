//PE 53: Combinatoric selections
//Problem: Find all combinatorial numbers (n, r) such that 1 <= n <= 100, and are greater than one million.
//Solution: We can modify Pascal's triangle with a sentinel value for when the number exceeds one million, and then count how many times it appears.
//Runtime: O(n^2)
#include "EulerUtils.hpp"

long long solve() {
    vector<vector<long long>> triangle(101, vector<long long>(101, 0));
    triangle[0][0] = 1;

    long long ans = 0LL;
    for (int i = 1; i <= 100; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            long long a = triangle[i - 1][j - 1];
            long long b = triangle[i - 1][j];
            if (a == -1 || b == -1) {
                triangle[i][j] = -1;
                ans++;
            }
            else {
                triangle[i][j] = a + b;
                if (triangle[i][j] > 1000000) {
                    triangle[i][j] = -1;
                    ans++;
                }
            }
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
