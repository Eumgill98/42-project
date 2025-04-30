#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed const &other);

        Fixed(int const n);
        Fixed(float const n);
    
        Fixed&	operator=(Fixed const &other);

        bool operator>(Fixed const &other) const;
        bool operator<(Fixed const &other) const;
        bool operator>=(Fixed const &other) const;
        bool operator<=(Fixed const &other) const;
        bool operator==(Fixed const &other) const;
        bool operator!=(Fixed const &other) const;

        Fixed operator+(Fixed const &other);
        Fixed operator-(Fixed const &other);
        Fixed operator*(Fixed const &other);
        Fixed operator/(Fixed const &other);

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream&   operator<<(std::ostream &o, Fixed const &fixed);

# endif /* __FIXED_HPP__ */