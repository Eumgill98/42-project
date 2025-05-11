#include "Cat.hpp"

Cat::Cat()
    : Animal()
{
    this->type = "Cat";
    this->_brain = new Brain;
    std::cout << "Cat  constructor is called!" << std::endl;
}

Cat::Cat(const Cat &copy)
    : Animal()
{
    this->type = copy.type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Cat copy constructor is called!" << std::endl;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat deconstructor is called!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    this->type = other.type;
    if (this->_brain)
        delete (this->_brain);
    this->_brain = new Brain(*other._brain);
    std::cout << "Cat assignation operator is called!" << std::endl;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat : Meow Meow Meow Meow  !!" << std::endl;
}

std::string Cat::getIdea(int idea_idx) const
{
    return (this->_brain->getIdea(idea_idx));
}

void Cat::setIdea(int idea_idx, std::string new_idea)
{
    this->_brain->setIdea(idea_idx, new_idea);
}