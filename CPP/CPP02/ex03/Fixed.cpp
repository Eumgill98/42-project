#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &other)
{
    this->_value = other.getRawBits();
}

Fixed::Fixed(int const n)
{
    this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
    this->_value = (int)roundf(n * (1 << this->_fractionalBits));
}

Fixed& Fixed::operator=(Fixed const &other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(Fixed const &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(Fixed const &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(Fixed const &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(Fixed const &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(Fixed const &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(Fixed const &other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(Fixed const &other)
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other)
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other)
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other)
{
    if (other._value == 0)
        throw std::runtime_error("Division by zero");
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++() 
{
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int) 
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed& Fixed::operator--() 
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--(int) 
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) 
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) 
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) 
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) 
{
    return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_value / (float)(1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
    return (int)(this->_value >> this->_fractionalBits);
}

std::ostream&   operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}