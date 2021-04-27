//PE 92: Square Digit Chains
//Problem: We will call the square digit of n the sum of the squares of its digits. Every positive integer will eventually end up in 89 or 1 after enough iterations.
//Find the amount of numbers under ten million which arrive at 89.
//Solution: Quite an easy one, we keep track of the chain until we find a number to which we already know the answer, and propagate
//it over the entire chain.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

int squareDigit(int n) {
    int ret = 0;
    while (n > 0) {
        ret += (n % 10) * (n % 10);
        n /= 10;
    }
    return ret;
}

long long solve() {
    vector<int> arrivesAt(10000001);
    arrivesAt[1] = 1;
    arrivesAt[89] = 89;
    for (int i = 1; i <= 10000000; i++) {
        if (arrivesAt[i])
            continue;

        stack<int> s;
        int curr = i;
        while (!arrivesAt[curr]) {
            s.push(curr);
            curr = squareDigit(curr);
        }

        while (!s.empty()) {
            arrivesAt[s.top()] = arrivesAt[curr];
            s.pop();
        }
    }

    return count_if(arrivesAt.begin(), arrivesAt.end(), [&](int i) -> bool { return i == 89; });
}

int main() {
    cout << solve() << '\n';
}