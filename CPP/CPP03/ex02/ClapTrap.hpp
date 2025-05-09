#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

# include <iostream>
# include <string>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hit_point;
        unsigned int _energy_point;
        unsigned int _attack_damage;

    public:
        ClapTrap();
        ClapTrap(const ClapTrap &copy);
        ClapTrap(std::string name);

        virtual ~ClapTrap();

        ClapTrap &operator=(const ClapTrap &other);

        virtual void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif /* __CLAPTRAP_HPP__ */