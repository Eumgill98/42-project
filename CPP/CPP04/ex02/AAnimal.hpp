#ifndef __AANIMAL_HPP__
#define __AANIMAL_HPP__

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    
    public:
        AAnimal();
        AAnimal(const AAnimal &copy);

        virtual ~AAnimal() = 0;

        AAnimal &operator=(AAnimal const &other);
        
        virtual std::string getType(void) const;
        virtual void makeSound() const = 0;
} ;

#endif /* __AANIMAL_HPP__ */