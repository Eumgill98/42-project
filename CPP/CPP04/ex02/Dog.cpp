#include "Dog.hpp"

Dog::Dog()
    : AAnimal()
{
    this->type = "Dog";
    this->_brain = new Brain;
    std::cout << "Dog constructor is called!!" << std::endl;
}

Dog::Dog(const Dog &copy) 
    : AAnimal()
{
    this->type = copy.type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Dog copy constructor is called!" << std::endl;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog deconstructor is called!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    this->type = other.type;
    if (this->_brain)
        delete (this->_brain);
    this->_brain = new Brain(*other._brain);
    std::cout << "Dog assignation operator is called!" << std::endl;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog : Bowwow Bowwow Bowwow Bowwow !!" << std::endl;
}

std::string Dog::getIdea(int idea_idx) const
{
    return (this->_brain->getIdea(idea_idx));
}

void Dog::setIdea(int idea_idx, std::string new_idea)
{
    this->_brain->setIdea(idea_idx, new_idea);
}