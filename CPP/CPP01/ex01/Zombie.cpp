#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << ": is destroyed!!" << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void) const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

Zombie  *zombieHorde(int N, std::string name)
{
    if (N < 1)
    {
        std::cout << "This function can't make less than 1 Zombie." << std::endl;
        return (NULL);
    }
    Zombie *zombies = new Zombie[N];
    if (zombies == NULL)
    {
        std::cout << "Allocate memory is failed." << std::endl;
    }
    int idx = 0;
    while (idx < N)
    {
        zombies[idx].set_name(name);
        idx++;
    }
    return (zombies);
}