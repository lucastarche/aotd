//PE 73: Counting Fractions in a Range
//Problem: Count the number of irreducible fractions between 1/3 and 1/2 such that d <= 12000
//Solution: We can employ bruteforce for this problem, given that d is quite small.
//We simply have to check if they are in the range, and if they are irreducible or not.
//Runtime: O(n^2)
#include "EulerUtils.hpp"

using fraction = pair<long long, long long>;

long long solve() {
    auto comp = [](fraction lhs, fraction rhs) {
        return (lhs.first * rhs.second) < (lhs.second * rhs.first);
    };

    long long ans = 0LL;

    for (long long n = 1; n <= 12000; n++) {
        for (long long d = n + 1; d <= 12000; d++) {
            if (comp(fraction(n, d), fraction(1, 3)))
                continue;
            if (comp(fraction(1, 2), fraction(n, d)))
                continue;
            if (gcd(n, d) != 1)
                continue;
            ans++;
        }
    }

    return ans - 2; //Dont count 1/3 and 1/2
}

int main() {
    cout << solve() << '\n';
}