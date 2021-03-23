//PE 45: Triangular, Pentagonal, Hexagonal
//Problem: Tn = n*(n+1)/2, Pn = n*(3*n-1)/2, Hn = n*(2*n - 1). We know that T285 = P165 = H143 = 40755. Find the next triangular number that is also pentagonal and hexagonal.
//Solution: We can start in the given number to find the next one. Then we can simply iterate, and on each iteration,
//we increase the lowest of the three numbers (the triangular, pentagonal or hexagonal), until we get to a point where the three are all equal.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long triangular(long long n) {
    return (n * (n + 1LL)) / 2LL;
}

long long pentagonal(long long n) {
    return (n * (3LL * n - 1LL)) / 2LL;
}

long long hexagonal(long long n) {
    return n * (2LL * n - 1LL);
}

long long solve() {
    long long t_i = 286LL, p_i = 166LL, h_i = 144LL;
    long long t = triangular(t_i), p = pentagonal(p_i), h = hexagonal(h_i);
    while (t != p || t != h) {
        if (t <= p && t <= h) {
            t_i++;
            t = triangular(t_i);
        } else if (p <= h) {
            p_i++;
            p = pentagonal(p_i);
        } else {
            h_i++;
            h = hexagonal(h_i);
        }
    }

    return h;
}

int main() {
    cout << solve() << '\n';
}
