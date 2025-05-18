#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);

        ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &other);

        std::string getType(void) const;
        void makeSound(void) const;
} ;

#endif /* __WRONGANIMAL_HPP__ */