//PE 52: Permuted multiples
//Problem: Find the positive integer x such that 2x, 3x,  4x, 5x and 6x are all permutations of one another
//Solution: We can run a complete search, skipping the numbers where 6x has more digits than x.
//Then, to check if the numbers are permutations, we can just sort the number string.
//Runtime: O(n log (n log n)) (a number has about log n digits, and sorting m numbers takes m log m time)
#include "EulerUtils.hpp"

long long solve() {
    long long tenpow = 10;
    for (long long curr = 1;; curr++) {
        if (curr * 6LL > tenpow) {
            curr = tenpow;
            tenpow *= 10LL;
            continue;
        }

        string numstr = to_string(2 * curr);
        sort(numstr.begin(), numstr.end());

        bool valid = true;
        for (long long i = 3; i <= 6; i++) {
            string s = to_string(curr * i);
            sort(s.begin(), s.end());
            if (numstr != s)
                valid = false;
        }

        if (valid)
            return curr;
    }

    //Unreachable return
    return -1;
}

int main() {
    cout << solve() << '\n';
}
