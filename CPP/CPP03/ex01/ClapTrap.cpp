#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("default"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
    : _name(copy._name), _hit_point(copy._hit_point), _energy_point(copy._energy_point), _attack_damage(copy._attack_damage)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_name << " ClapTrap Deconstructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other) {
        this->_name = other._name;
        this->_hit_point = other._hit_point;
        this->_energy_point = other._energy_point;
        this->_attack_damage = other._attack_damage;
    }
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_hit_point == 0 || this->_energy_point == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't attack!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_point == 0)
        std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
    else if (this->_hit_point > amount)
    {
        this->_hit_point -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
    {
        this->_hit_point = 0;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_point == 0 || this->_energy_point == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't repaired!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " hit points" << std::endl;;
    this->_energy_point--;
    this->_hit_point += amount;
    std::cout << "ClapTrap " << this->_name << " now has " << this->_hit_point << " hit points" << std::endl;
}