//PE 74: Digit Factorial Chains
//Problem: It can be proven that we will always get to a cycle by repeatedly applying the digit factorial function to an integer,
//that is, f(n) is the sum of the factorials of its digits. Get the number of integers such that the chain of integers they generate have exactly 60 terms distinct and are under one million.
//Solution: We can simply calculate the digit factorial for each number. To avoid having to calculate it more than once, we can store
//the solution in a hashmap once we have it for a certain n.
//Runtime: O(n log n)
#include "EulerUtils.hpp"

long long digit_factorial(long long n) {
    long long res = 0;
    while (n > 0) {
        res += factorial(n % 10);
        n /= 10;
    }
    return res;
}

unordered_map<long long, long long> table;
long long get_cycle_length(long long n) {
    if (table[n] == -1)
        return 0;
    if (table[n] != 0)
        return table[n];

    table[n] = -1;
    table[n] = get_cycle_length(digit_factorial(n)) + 1;
    return table[n];
}

long long solve() {
    for (long long i = 0; i < 1000000; i++) {
        get_cycle_length(i);
    }

    long long ans = 0;
    for (int i = 0; i < 1000000; i++) {
        if (table[i] == 60) {
            ans++;
        }
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}