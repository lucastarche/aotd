//Ternary Search
//Look for a minimum in a function that decreases, and then increases, or a maximum in a function that increases, and then decreases. Works similar to binary search.
//Best case complexity: O(log n)
//Average case complexity: O(log n)
//Worst case complexity: O(log n)
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

const double EPSILON = 1e-12;

//Note: this values are defined globally to make it easier to define the lambda
double a, b, c;

//In this case, minimize ax^2 + bx + c between l and r, for a > 0.
double TernarySearch(double (*f)(double), double l, double r) {
    if (r - l < EPSILON) {
        double x = r - l;
        return f(x);
    }
    double oneThird = (2 * l + r) / 3;
    double twoThirds = (l + 2 * r) / 3;
    if (f(oneThird) < f(twoThirds)) {
        return TernarySearch(f, l, twoThirds);
    } else {
        return TernarySearch(f, oneThird, r);
    }
}

int main() {
    cin >> a >> b >> c;
    double l, r;
    cin >> l >> r;
    double ans = TernarySearch([](double x) { return (a * x * x + b * x + c); }, l, r);
    cout << setprecision(10) << ans << '\n';
}
