#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
        
    public:
        Dog();
        Dog(const Dog &copy);

        ~Dog();

        Dog &operator=(const Dog &other);
        
        void makeSound(void) const;
        std::string getIdea(int idea_idx) const;
        void setIdea(int idea_idx, std::string new_idea);
} ;

#endif /* __DOG_HPP__ */