#include "WrongDog.hpp"

WrongDog::WrongDog()
    : WrongAnimal()
{
    this->type = "WrongDog";
    std::cout << "WrongDog constructor is called!" << std::endl;
}

WrongDog::WrongDog(const WrongDog &copy)
    : WrongAnimal()
{
    this->type = copy.type;
    std::cout << "WrongDog copy constructor is called!" << std::endl;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog deconstructor is called!" << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
    this->type = other.type;
    std::cout << "WrongDog assignation operator is called!" << std::endl;
    return (*this);
}

void WrongDog::makeSound(void) const
{
    std::cout << "WrongDog : WrongBowwow WrongBowwow WrongBowwow WrongBowwow !!" << std::endl; 
}