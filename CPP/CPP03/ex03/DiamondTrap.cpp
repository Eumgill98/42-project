#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = "default";
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 30;
    std::cout << "DiamondTrap " << this->_name << " Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy._name + "_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = copy._name;
    this->_hit_point = copy._hit_point;
    this->_energy_point = copy._energy_point;
    this->_attack_damage = copy._attack_damage;
    std::cout << "DiamondTrap " << this->_name << " Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = name;
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 30;
    std::cout << "DiamondTrap " << this->_name << " Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " Deconstructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
        this->_hit_point = other._hit_point;
        this->_energy_point = other._energy_point;
        this->_attack_damage = other._attack_damage;
    }
    std::cout << "DiamondTrap " << this->_name << " Assignation operator called" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name is " << this->_name << " and ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}