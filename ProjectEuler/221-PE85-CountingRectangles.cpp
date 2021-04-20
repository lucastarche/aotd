//PE 85: Counting Rectangles
//Problem: Find the dimensions of a rectangle such that the amount of subrectangles contained inside of it is the smallest possible.
//Solution: This reminded me of a math olympiad problem, so I went with that solution.
//The idea is that we can describe uniquely every subrectangle with four numbers: start and end on each axis.
//We have n + 1 segments in the x axis, and m + 1 segments in the y axis, so we can use the formula: n * (n + 1) * m * (m + 1) / 4,
//which represents choosing first a segment, and then one which is greater than the first.
//Runtime: O(n^2)
#include "EulerUtils.hpp"

long long rectangles(long long i, long long j) {
    return i * (i + 1) * j * (j + 1) / 4;
}

long long solve() {
    long long limit = 0, target = 2000000;
    while ((limit + 1) * limit / 2 < target)
        limit++;

    long long ans = 0, ans_val = 0;
    for (long long i = 0; i < limit; i++) {
        for (long long j = 0; j < limit; j++) {
            if (abs(rectangles(i, j) - target) < abs(ans_val - target)) {
                ans = i * j;
                ans_val = rectangles(i, j);
            }
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}