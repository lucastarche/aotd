//Binomial Coefficient (Factorial version)
//This takes advantage of the fact that the we can define the number as n! / (k! * (n-k)!).
//Runtime: O(n). However, it wont work for large n unless you have arbitrarily long numbers.
#include <bits/stdc++.h>

using namespace std;

long long BinomialCoefficient(int n, int k) {
    vector<long long> factorial;
    factorial.push_back(1);
    for (long long i = 1; i <= n; i++) {
        int s = (int)factorial.size() - 1;
        factorial.push_back(factorial[s - 1] * i);
    }

    return factorial[n] / (factorial[k] * factorial[n - k]);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << BinomialCoefficient(n, k) << '\n';
}