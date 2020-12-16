//Extended Euclid's algorithm
//Returns three numbers, x, y and g. 
//Given a and b, it returns an integer solution to an equation of the form: ax + by = gcd(a, b).
//Runtime: O(log n) (same as Euclid's algorithm).
#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> ExtendedEuclid(int a, int b) {
    if (b == 0) return {1, 0, a};

    int x, y, g;
    tie(x, y, g) = ExtendedEuclid(b, a % b);
    return {y, x - (a / b) * y, g};
}

int main() {
    int a, b;
    cin >> a >> b;

    int x, y, g;
    tie(x, y, g) = ExtendedEuclid(a, b);
    cout << x << " " << y << " " << g << '\n';
}