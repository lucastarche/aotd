//PE 71: Ordered Fractions
//Problem: If we order all reduced proper fractions (between 0 and 1), for which d <= 1000000,
//find the numerator of the fraction to the immediate left of 3/7.
//Solution: Instead of generating every fraction, we can perform an incremental search, on which we increase the numerator if we are under the target, and the denominator otherwise.
//This, plus keeping track of the biggest fraction lower than 3/7 gives a fast solution.
//Runtime: O(n)
#include "EulerUtils.hpp"

using fraction = pair<long long, long long>;

long long solve() {
    const int limit = 1000000;
    auto comp = [](fraction lhs, fraction rhs) {
        return (lhs.first * rhs.second) < (lhs.second * rhs.first);
    };

    fraction curr = { 0, 1 }, best = { 0, 1 };
    while (curr.first <= limit || curr.second <= limit) {
        if (comp(curr, fraction(3, 7))) {
            if (comp(best, curr)) {
                best = curr;
            }
            if (curr.first == limit)
                break;
            curr.first++;
        } else {
            if (curr.second == limit)
                break;
            curr.second++;
        }
    }

    return best.first / gcd(best.first, best.second);
}

int main() {
    cout << solve() << '\n';
}