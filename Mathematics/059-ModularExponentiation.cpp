//Modular Exponentiation
//The idea behind this algorithm is that we can calculate x^(2n) in constant time thanks to the fact that x^n * x^n = x^2n.
//If n is odd, we can calculate x^(2n + 1) as x^n * x^n * x, also in constant time.
//Given that we can make a recursion, and we call the function in at most log n operations.
//Runtime: O(log n). Using a for loop, it would have run in O(n).
//The function returns x^n % m.
#include <bits/stdc++.h>

using namespace std;

int ModularExponentiation(int x, int n, int m) {
    if (x == 0)
        return 0;
    if (n == 0)
        return 1; //x^0 = 1 if x != 0
    long long u = ModularExponentiation(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1)
        u = (u * x) % m;
    return (int)u;
}

int main() {
    int x, n, m;
    cin >> x >> n >> m;
    cout << ModularExponentiation(x, n, m) << '\n';
}
