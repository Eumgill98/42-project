#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &copy);

        ~Cat();

        Cat &operator=(const Cat &other);
        
        void makeSound(void) const;
} ;

#endif /* __CAT_HPP__ */