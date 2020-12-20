//Line From Two Points
//We can get the line given two points, by just calculating the slope, and then replacing to get c (the point where x = 0). 
//Runtime: O(1)
#include "Line.cpp"
#include "Point.cpp"


Line getLine(Point p1, Point p2) {
    if (p1.getX() > p2.getX()) swap(p1, p2);
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    
    double a = dy/dx;
    double c = a * -p1.getX() + p1.getY();
    
    bool vertical = (p1.getX() == p2.getX());


    return Line(a, c, vertical);
}

int main() {
    Point a, b;
    double x, y;
    cin >> x >> y;
    a = Point(x, y);
    cin >> x >> y;
    b = Point(x, y);

    Line ans = getLine(a, b);
    cout << ans.getA() << ' ' << ans.getB() << ' ' << ans.getC() << '\n';
}