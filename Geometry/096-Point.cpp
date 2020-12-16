//Point
//The most basic geometrical element. In this case we are using doubles to have more accurate coordinates.
//Consists of n independent coordinates, where n is the dimensions we are working with (usually 2).
//Runtime: dist runs in O(1), and returns the Euclidean distance.  
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
};

int main() {
    Point a, b;
    double x, y;
    cin >> x >> y;
    a = Point(x, y);
    cin >> x >> y;
    b = Point(x, y);

    cout << a.dist(b) << '\n';
}