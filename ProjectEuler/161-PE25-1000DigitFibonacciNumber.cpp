//PE 25: 1000-Digit Fibonacci Number
//Define f(1) = 1, f(2) = 1, f(n) = f(n - 1) + f(n - 2) for n > 2. Find the first n for which f(n) has 1000 digits.
//Solution: We can solve this problem as yet another BigInteger problem.
//Runtime: O(n^2), where n is the number of digits.
//Bonus solution with O(1) runtime:
//As n tends to infinity, we can estimate f(n) as phi^(n - 1), where phi is the golden ratio ((1 + sqrt(5)) / 2).
//We can also get the number of digits of n by doing floor(log10(n)) + 1
//Then we can solve the equation floor(log10(phi^(n - 1))) + 1 = 1000
//We can ditch the floor, and simplify to log10(phi^(n - 1)) = 999
//We cancel the log: phi^(n - 1) = 10^999
//We take log base phi both sides: n - 1 = log_phi(10^999)
//We take out the ^999 by the properties of logarithms: n - 1 = 999*log_phi(10)
//We get our answer: n = ceil(999 * log_phi(10) + 1)
//Note: We take the ceiling because the floor will be the term before the one we are looking for if it has a fractional part.
#include "EulerUtils.hpp"

long long solve() {
    int digits = 2000;
    int order = 0;
    vector<int> fib1(digits, 0);
    vector<int> fib2(digits, 0);
    vector<int> swp(digits, 0);

    fib1[0] = 1;
    fib2[0] = 1;
    int index = 2;
    while (fib1[999] == 0) {
        int carry = 0;
        for (int j = 0; j <= order; j++) {
            int sum = fib1[j] + fib2[j] + carry;
            swp[j] = sum % 10;
            carry = sum / 10;
            if (j == order && carry > 0)
                order++;
        }

        swap(fib1, fib2);
        swap(fib1, swp);
        index++;
    }

    return (long long)index;
}

int main() {
    cout << solve() << '\n';
}
