#include "Dog.hpp"

Dog::Dog()
    : Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor is called!!" << std::endl;
}

Dog::Dog(const Dog &copy)
    : Animal()
{
    this->type = copy.type;
    std::cout << "Dog copy constructor is called!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog deconstructor is called!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    this->type = other.type;
    std::cout << "Dog assignation operator is called!" << std::endl;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog : Bowwow Bowwow Bowwow Bowwow !!" << std::endl;
}