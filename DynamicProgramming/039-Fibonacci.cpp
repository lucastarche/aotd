//Fibonacci numbers
//It is a classic sequence, and one of the examples of why DP is so powerful.
//If we plant the problem as recursive (without tabulation / memoization), we get an algorithm that runs in O(2^n).
//However, we can reduce that to a linear time, and now it runs in O(n).
//Now, the main problem is calculating for a big n, given that it grows exponentially. For that, we can tweak it a bit, to calculate it mod M. The most common is usually 1e9 + 7, which is a big prime, but it is left as an implementation detail.
#include <bits/stdc++.h>

using namespace std;

long long Fibonacci(int n) {
    vector<long long> fib(n + 2);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n;
    cin >> n;
    cout << "The nth fibonacci number is: " << Fibonacci(n) << '\n';
}
