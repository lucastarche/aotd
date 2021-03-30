//PE 64: Odd Period Square Roots
//Problem: All square roots are periodic when written as a continued fraction. For example, sqrt(7) = [2, (1, 1, 1, 4)]. Find the number of continued fractions for sqrt(N) which have an odd period for N <= 10000
//Solution: Looking on Wikipedia, i found a recursive definition for every term of the continued fraction.
//Then it is just a matter of implementing it to get the answer.
//Runtime: O(n * period(n))
#include "EulerUtils.hpp"

long long getPeriod(long long x) {
    long long sqrtx = (long long)sqrt(x);
    long long a = sqrtx;
    long long M = 0, D = 1;

    long long ans = 0;
    while (a != 2 * sqrtx) {
        M = (long long)(D * a - M);
        D = (long long)((x - M * M) / D);
        a = (long long)((sqrtx + M) / D);
        ans++;
    }

    return ans;
}

long long solve() {
    queue<long long> squares;
    for (long long i = 0; i <= 100; i++) {
        squares.push(i * i);
    }

    long long ans = 0;
    for (long long i = 0; i <= 10000; i++) {
        if (i == squares.front()) {
            squares.pop();
            continue;
        }

        if (getPeriod(i) % 2 == 1) ans++;
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}
