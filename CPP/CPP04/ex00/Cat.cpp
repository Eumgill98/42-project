#include "Cat.hpp"

Cat::Cat()
    : Animal()
{
    this->type = "Cat";
    std::cout << "Cat  constructor is called!" << std::endl;
}

Cat::Cat(const Cat &copy)
    : Animal()
{
    this->type = copy.type;
    std::cout << "Cat copy constructor is called!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat deconstructor is called!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    this->type = other.type;
    std::cout << "Cat assignation operator is called!" << std::endl;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat : Meow Meow Meow Meow  !!" << std::endl;
}