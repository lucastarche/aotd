//PE 91: Right Triangles With Integer Coordinates
//Problem: Given a plane where 0 <= x, y <= 50, determine the amount of right angled triangles with integer coordinates and which have (0, 0) as a vertice.
//Solution: We can iterate through every point (a, b) and (c, d), and then check if the triangle formed if a right triangle or not.
//For this, we can form three lines, and check if any of these two are perpendicular (one has the negative inverse of the other) or not.
//Runtime: O(n^4)
#include "EulerUtils.hpp"

bool arePerpendicular(pair<int, int> m1, pair<int, int> m2) {
    pair<int, int> invNegM2 = { -m2.second, m2.first };
    return (m1.first * invNegM2.second == m1.second * invNegM2.first);
}

bool isRightTriangle(int a, int b, int c, int d) {
    pair<int, int> m1 = { b, a };
    pair<int, int> m2 = { d, c };
    pair<int, int> m3 = { d - b, c - a };

    return (arePerpendicular(m1, m2) || arePerpendicular(m1, m3) || arePerpendicular(m2, m3));
}

long long solve() {
    const int max_coord = 50;
    long long ans = 0;

    for (int a = 0; a <= max_coord; a++) {
        for (int b = 0; b <= max_coord; b++) {
            if (a == 0 && b == 0)
                continue;
            for (int c = 0; c <= max_coord; c++) {
                for (int d = 0; d <= max_coord; d++) {
                    if (c == 0 && d == 0)
                        continue;
                    if (a == c && b == d)
                        continue;
                    ans += isRightTriangle(a, b, c, d);
                }
            }
        }
    }

    //Note: We divide by two since we are counting (0, 0) (a, b) (c, d) and (0, 0) (c, d) (a, b)
    //as two different triangles
    return ans / 2;
}

int main() {
    cout << solve() << '\n';
}