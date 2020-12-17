#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

class Point {
    private:
        double x, y;
    public:
        Point() : x{0.0}, y{0.0} { }
        Point(double x, double y) : x{x}, y{y} { }

        bool operator==(Point other) const {
            return (abs(other.x - x) < EPS && abs(other.y - y) < EPS);
        }

        double dist(Point other) const {
            double dx = x - other.x;
            double dy = y - other.y;
            return sqrt(dx * dx + dy * dy);
        }

        double getX() {return x;}
        double getY() {return y;}
};