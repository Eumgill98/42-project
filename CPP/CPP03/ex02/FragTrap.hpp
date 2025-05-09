#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap(std::string name);

        ~FragTrap();

        FragTrap &operator=(const FragTrap &other);

        void highFivesGuys(void);
};

#endif /* __FRAGTRAP_HPP__ */