#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &other);

        ~Brain();

        Brain &operator=(const Brain &other);

        std::string getIdea(int idea_idx) const;
        void setIdea(int idea_idx, std::string new_idea);

} ;

#endif /* __BRAIN_HPP__ */