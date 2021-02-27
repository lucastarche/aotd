//PE 33: Digit Cancelling Fractions
//Problem: Hard to explain, you should probably read the statement for this one.
//Solution: We can bruteforce through each possible pair of fractions, 
//and we can check in constant time if the cancelling of a digit yields the same number or not.
//Runtime: O(n^2)
#include "EulerUtils.hpp"

long long solve() {
    long long num = 1LL, denom = 1LL;

    for (int i = 10; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (i % 10 == 0 && j % 10 == 0) continue;

            //Second condition: i / j == (i / 10) / (j % 10)
            if (i % 10 == (int)(j / 10) 
                    && (i * (j % 10)) == (j * (int)(i / 10))) {
                num *= (long long) i;
                denom *= (long long) j;

            }

        }
    }

    return (long long)(denom / num);
}

int main() {
    cout << solve() << '\n';
}
