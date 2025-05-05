#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(4), Fixed(0));
    Point c(Fixed(2), Fixed(3));
    Point p(Fixed(2), Fixed(1));
    Point edge(Fixed(2), Fixed(0)); 

    std::cout << "p point X Y : (" << p.getX().toFloat() << "," << p.getY().toFloat() << ")" << std::endl;
    std::cout << "edge point X Y : (" << edge.getX().toFloat() << "," << edge.getY().toFloat() << ")" << std::endl;
    std::cout << "p inside triangle? " << (bsp(a, b, c, p) ? "Yes" : "No") << std::endl;
    std::cout << "edge point inside triangle? " << (bsp(a, b, c, edge) ? "Yes" : "No") << std::endl;

    return 0;
}