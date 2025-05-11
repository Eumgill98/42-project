#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor is called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
    : type(copy.type)
{
    std::cout << "WrongAnimal copy constructor is called!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal deconstructor is called!" << std::endl; 
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    this->type = other.type;
    std::cout << "WrongAnimal assignation operator is called!" << std::endl;
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal : WrongAni WrongAni WrongAni WorngAni !!" << std::endl;
}