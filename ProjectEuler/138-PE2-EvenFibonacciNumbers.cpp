//PE2: Even Fibonacci Numbers
//Shortened statement: Find the sum of all the even terms whose values is less or equal than 4 million of the Fibonacci sequence.
//Solution: We can calculate the terms of the fibonacci sequence up to 4 million, and add them as we go.
//Runtime: O(n), where n is the amount of terms in the sequence we calculate.
#include <bits/stdc++.h>

using namespace std;

long long solve() {
    long long ans = 0;
    long long f1 = 1LL, f2 = 1LL;
    while (f1 <= 4000000LL) {
        long long temp = f1;
        f1 = f1 + f2;
        f2 = temp;
        if (f1 % 2 == 0)
            ans += f1;
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}