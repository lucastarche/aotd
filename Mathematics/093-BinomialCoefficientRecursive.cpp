//Binomial Coefficients (Recursive Version)
//The binomial coefficient represents the number of ways one can choose a subset of k elements out of a set of n elements.
//In English, this means taking k elements of a pool of n total elements, without taking into account the order we take them out.
//We can use a recursive formula, which is directly represented in the code.
//Runtime: O(2^n)
#include <bits/stdc++.h>

using namespace std;

int BinomialCoefficient(int n, int k) {
    if (k == 0 || n == k)
        return 1;
    return BinomialCoefficient(n - 1, k - 1) + BinomialCoefficient(n - 1, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << BinomialCoefficient(n, k) << '\n';
}