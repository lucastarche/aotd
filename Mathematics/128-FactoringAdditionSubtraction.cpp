//Factoring with Additions and Subtractions
//Given a number which is the product of two odd numbers, we determine the one which is less than or equal to sqrt(n).
//This algorithm is based on Fermat's method.
//Runtime: O(sqrt(n))
//Note: there is a faster version, which runs in O(n^(1/3)), that is, cube root of n.
#include <bits/stdc++.h>

using namespace std;

//Note: n must be odd
int FactoringAS(int n) {
    int sqrtn = (int)sqrt(n);
    int a = 2 * sqrtn + 1;
    int b = 1;
    int r = sqrtn * sqrtn - n;

    while (r != 0) {
        r += a;
        a += 2;
        while (r > 0) {
            r -= b;
            b += 2;
        }
    }

    return (a - b) / 2;
}

int main() {
    int n;
    cin >> n;
    cout << FactoringAS(n) << '\n';
}