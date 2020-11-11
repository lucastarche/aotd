//Euclid's Algorithm
//This is a very old and well-known algorithm, which has over 2000 years of age.
//It calculates the greatest common divisor of two numbers, that is, the greatest integer that divides both numbers.
//It can be use dto get the Lowest Common Multiple as well, and has many applications in mathematics, like for example, getting irreducible fractions.
//Runtime: O(log10 n)
#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int LCM(int a, int b) {
    return a * (b / GCD(a, b));
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "GCD: " << GCD(a, b) << '\n';
    cout << "LCM: " << LCM(a, b) << '\n';
}
