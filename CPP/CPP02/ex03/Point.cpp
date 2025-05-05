#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::~Point()
{
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{
}

Point::Point(Point const &other): _x(other._x), _y(other._y)
{
}

Point& Point::operator=(Point const &other)
{
    if (this != &other)
    {
        _x = other._x;
        _y = other._y;
    }
    return (*this);
}

Fixed Point::getX() const
{
    return (this->_x);
}

Fixed Point::getY() const
{
    return (this->_y);
}