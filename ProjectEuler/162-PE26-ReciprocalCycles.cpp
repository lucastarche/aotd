//PE 26: Reciprocal Cycles
//Problem: Find the value of d < 1000 such that 1 / d cointains the longest recurring cycle in the decimal fraction part.
//Solution: Note that a cycle occurs when the remainder modulo i has already been used. 
//We can keep track of the visited remainders, and then output the number for which the most remainders are visited.
//This remainder has to be different from 0, because otherwise it ends in a cycle of 0.
//Runtime: O(n^2)
//Why O(n^2)? This is because the maximum amount of remainders a number may have modulo n, distinct from 0, is n - 1.
//That means that in the worst case, we will run the inner loop for O(n) cycles, giving O(n^2) as the resulting complexity.

#include "EulerUtils.hpp"

long long solve() {
    int ansVal = 0, ans = 0;
    for (int i = 2; i < 1000; i++) {
        vector<bool> used(i, false);

        bool hasCycle = true;
        int quotient = 0, remainder = 10;
        
        while (true) {
            quotient = remainder / i;
            remainder = remainder % i;
            if (remainder == 0) {
                hasCycle = false;
                break;
            }

            if (used[remainder]) {
                break;
            }
            else {
                used[remainder] = true;
            }
            remainder *= 10;
        } 

        if (!hasCycle) continue;

        int curr = 0;
        for (int j = 0; j < i; j++) {
            curr += (int)used[j];
        }

        if (curr > ansVal) {
            ansVal = curr;
            ans = i;
        }
    }

    return (long long) ans;
}

int main() {
    cout << solve() << '\n';
}
