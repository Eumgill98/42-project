#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap(std::string name);

        ~DiamondTrap();

        DiamondTrap &operator=(const DiamondTrap &other);
        
        void whoAmI(void);
        void attack(const std::string &target);
};

#endif /* __DIAMONDTRAP_HPP__ */