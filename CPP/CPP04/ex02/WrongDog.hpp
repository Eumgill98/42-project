#ifndef __WRONGDOG_HPP__
#define __WRONGDOG_HPP__

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
    protected:
        std::string type;
    
    public:
        WrongDog();
        WrongDog(const WrongDog &copy);

        ~WrongDog();

        WrongDog &operator=(const WrongDog &other);

        void makeSound(void) const;
} ;

#endif /* __WRONGDOG_HPP__ */