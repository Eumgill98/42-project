#include "Point.hpp"

Fixed crossProduct(Point const &a, Point const &b, Point const &p) {
    Fixed abx = b.getX() - a.getX();
    Fixed aby = b.getY() - a.getY();
    Fixed apx = p.getX() - a.getX();
    Fixed apy = p.getY() - a.getY();

    return (abx * apy - aby * apx);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1 = crossProduct(a, b, point);
    Fixed cross2 = crossProduct(b, c, point);
    Fixed cross3 = crossProduct(c, a, point);
    
    if (cross1 == Fixed(0) || cross2 == Fixed(0) || cross3 == Fixed(0))
        return false;

    bool allPositive = cross1 > 0 && cross2 > 0 && cross3 > 0;
    bool allNegative = cross1 < 0 && cross2 < 0 && cross3 < 0;

    return allPositive || allNegative;
}