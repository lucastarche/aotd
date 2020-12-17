//Point Rotation
//By using a rotation/transformation 2x2 matrix (for 2D space), we can rotate a point respect to the origin.
//The matrix in question is:
//|cos(theta) -sin(theta)|
//|sin(theta) cos(theta)|
//Runtime: O(1)
#include "Point.cpp"

Point rotate(Point p, double deg) {
    double rad = deg * M_PI / 180.0;
    double x = p.getX() * cos(rad) - p.getY() * sin(rad);
    double y = p.getX() * sin(rad) + p.getY() * cos(rad);
    return Point(x, y);
}

int main() {
    Point a;
    double x, y, deg;
    cin >> x >> y >> deg;
    a = Point(x, y);

    Point ans = rotate(a, deg);
    cout << ans.getX() << ' ' << ans.getY() << '\n';
}