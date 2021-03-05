//PE 39: Integer Right Triangles
//Problem: Find the number of p <= 1000 such that the number of integer solutions for a^2 + b^2 = c^2 and a + b + c = p is maximised
//Solution: Given the small bounds, we can iterate through every p, a and b, and check if the conditions are true or not.
//Runtime: O(n^3)
#include "EulerUtils.hpp"

long long solve() {
    long long ans = 0LL, solutions = 0LL;
        
    for (long long p = 1LL; p <= 1000LL; p++) {
        long long curr = 0LL;
        for (long long a = 1LL; a <= p; a++) {
            for (long long b = a; b <= p; b++) {
                long long c = p - a - b;
                if (a * a + b * b == c * c) curr++;
            }
        }

        if (curr > solutions) {
            solutions = curr;
            ans = p;
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
