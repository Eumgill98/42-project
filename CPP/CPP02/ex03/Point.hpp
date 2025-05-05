#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point {
    private:
        Fixed _x;
        Fixed _y;

    public:
        Point();
        ~Point();
        Point(Fixed const x, Fixed const y);
        Point(Point const &other);

        Point& operator=(Point const &opther);
        Fixed getX() const;
        Fixed getY() const;
};

#endif /* __POINT_HPP__ */