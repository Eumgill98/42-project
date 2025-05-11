#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(const Animal &copy);

        virtual ~Animal();

        Animal &operator=(const Animal &other);

        std::string getType(void) const;
        virtual void makeSound(void) const;
} ;

#endif /* __ANIMAL_HPP__ */