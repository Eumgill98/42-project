#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *_brain;
        
    public:
        Dog();
        Dog(const Dog &copy);

        virtual ~Dog();

        Dog &operator=(const Dog &other);
        
        virtual void makeSound(void) const;
        std::string getIdea(int idea_idx) const;
        void setIdea(int idea_idx, std::string new_idea);
} ;

#endif /* __DOG_HPP__ */