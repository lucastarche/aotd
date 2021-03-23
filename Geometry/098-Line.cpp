//Line
//We can represent a line in the form of ax + by = c in the 2D plane.
//Note that we can also use just two variables if we use the form a/bx + y = c/b, but we can not represent vertical lines.
//We can assume b = 0 if the line is vertical, and b = 1 otherwise, so we will just represent b as a boolean.
//Runtime: O(1)
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

class Line {
private:
    double a, c;
    bool vertical;

public:
    Line(double a, double c, bool vertical)
        : a { a }
        , c { c }
        , vertical { vertical } { }

    Line()
        : a { 0 }
        , c { 0 }
        , vertical { false } { }

    bool isParallel(Line other) const {
        return (abs(other.a - a) < EPS && (other.vertical == vertical));
    }

    bool operator==(Line other) const {
        return isParallel(other) && abs(other.c - c) < EPS;
    }
};

int main() {
    Line a, b;
    double x, y;
    bool vertical;
    cin >> x >> y >> vertical;
    a = Line(x, y, vertical);
    cin >> x >> y >> vertical;
    b = Line(x, y, vertical);

    cout << a.isParallel(b) << '\n';
}