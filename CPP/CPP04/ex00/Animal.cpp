#include "Animal.hpp"

Animal::Animal()
    : type("Animal")
{
    std::cout << "Animal constructor is called!" << std::endl;
}

Animal::Animal(const Animal &copy)
    : type(copy.type)
{
    std::cout << "Animal copy constructor is called!" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal deconstructor is called!" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    this->type = other.type;
    std::cout << "Animal assignation operator is called!" << std::endl;
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal : Ani Ani Ani Ani !!" << std::endl;
}