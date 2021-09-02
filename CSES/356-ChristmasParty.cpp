//Christmas Party
//Problem: Given n children, each with a gift, find the number of ways modulo 1e9 + 7 they can distribute the gifts such that no child recieves their own gift
//Solution: This problem is asking us to get the number of dearrangements of n elements there are
//This is expressed as !n, and we know !n = (n - 1) * (!(n - 1) + !(n - 2)), with !0 = 1 and !1 = 0
//We can do this iteratively with no extra space by keeping track of !(n - 1) and !(n - 2)
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    long long last = 1, curr = 0;

    for (int i = 2; i <= n; ++i) {
        long long temp = (i - 1) * (last + curr) % MOD;
        last = curr;
        curr = temp;
    }

    cout << curr << '\n';
}