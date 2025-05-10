#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &copy);

        ~Dog();

        Dog &operator=(const Dog &other);
        
        void makeSound(void) const;
} ;

#endif /* __DOG_HPP__ */