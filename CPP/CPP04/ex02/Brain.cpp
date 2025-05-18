#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++) 
		this->ideas[i] = 'A' + (i % 26); 
    std::cout << "Brain constructor is called!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copy constructor is called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor is called!" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	int i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		i++;
	}
	std::cout << "Brain assignation operator is called!" << std::endl;
	return (*this);
}

std::string Brain::getIdea(int idea_idx) const
{
	if (idea_idx < 0 || idea_idx >= 100)
    	return ("idea_idx is over the range (0 ~ 99)");
    return (this->ideas[idea_idx]);
}

void Brain::setIdea(int idea_idx, std::string new_idea)
{
	if (idea_idx < 0 || idea_idx >= 100)
	{
		std::cout << "Error : " << idea_idx << " is not valid idx range (valid : 0 ~ 99)" << std::endl;
		return ;
	}
	this->ideas[idea_idx] = new_idea;
}