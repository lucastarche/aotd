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

    double getA() { return a; }
    double getB() { return (double)vertical; }
    double getC() { return c; }
};