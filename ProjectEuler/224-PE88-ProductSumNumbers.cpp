//PE 88: Product Sum Numbers
//Problem: Given a number k, we define the minimum product sum number k as the minimum number which can be expressed as
//both a product and a sum, both of exactly k terms. Find the sum of all k <= 12000, counting repetitions only once.
//Solution: We can keep track of the current product, sum, and the maximum factor that we already have in the product, to explore
//the search space in such a way that me always keep the minimum for each k.
//Then we just sort the array, eliminate the repetitions, and sum them all up.
//Runtime: O(k^2), because it can be proven that the maximum possible number for every k is 2 * k.
#include "EulerUtils.hpp"

const long long INF = 1e9;
const long long max_k = 12000;
vector<long long> best(max_k + 1, INF);

void explore(long long prod, long long sum, long long min_factor) {
    if (prod - sum > max_k)
        return;
    best[prod - sum] = min(best[prod - sum], prod);
    for (long long i = min_factor; i <= 2 * max_k; i++) {
        explore(prod * i, sum + i - 1, i);
    }
}

long long solve() {
    explore(1, 0, 2);

    sort(best.begin() + 2, best.end());

    auto last = unique(best.begin() + 2, best.end());
    best.erase(last, best.end());

    return accumulate(best.begin() + 2, best.end(), 0);
}

int main() {
    cout << solve() << '\n';
}