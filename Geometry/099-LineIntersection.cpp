//Line Intersection
//We can get the intersection of two lines by solving a system of two equations. In matrix form:
//|a1 b1 c1|
//|a2 b2 c2|
//This system has only one solution if the lines are not parallel.
//Runtime: O(1)
#include "Line.cpp"
#include "Point.cpp"

//Note: we must make sure the lines are not parallel before calling the method.
Point lineIntersection(Line line1, Line line2) {
    double upper = (line2.getB() * line1.getC() - line1.getB() * line2.getC());
    double lower = (line2.getA() * line1.getB() - line1.getA() * line2.getB());
    double x = upper / lower;

    double y = 0.0;
    if (line1.getB() > EPS)
        y = -(line1.getA() * x + line1.getC());
    else
        y = -(line2.getA() * x + line2.getC());

    return Point(x, y);
}

int main() {
    Line a, b;
    double x, y;
    bool vertical;
    cin >> x >> y >> vertical;
    a = Line(x, y, vertical);
    cin >> x >> y >> vertical;
    b = Line(x, y, vertical);

    Point ans = lineIntersection(a, b);
    cout << ans.getX() << ' ' << ans.getY() << '\n';
}