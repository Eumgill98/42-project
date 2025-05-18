#include "AAnimal.hpp"

AAnimal::AAnimal()
    : type("AAimal")
{
    std::cout << "AAnimal constructor is called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
    : type(copy.type)
{
    std::cout << "AAnimal copy constructor is called!" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal deconstructor is called!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    this->type = other.type;
    std::cout << "AAnimal assignation operator is called!" << std::endl;
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}

void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal can't make sound" << std::endl;
}