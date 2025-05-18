#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain *_brain;

    public:
        Cat();
        Cat(const Cat &copy);

        virtual ~Cat();

        Cat &operator=(const Cat &other);
        
        virtual void makeSound(void) const;
        std::string getIdea(int idea_idx) const;
        void setIdea(int idea_idx, std::string new_idea);
} ;

#endif /* __CAT_HPP__ */