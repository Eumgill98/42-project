#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed 
{
    private:
        int                 _value;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed &other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

# endif /* __FIXED_HPP__ */