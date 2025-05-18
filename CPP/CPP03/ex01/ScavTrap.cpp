#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("default")
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap " << this->_name << " Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
    : ClapTrap(copy._name)
{
    this->_hit_point = copy._hit_point;
    this->_energy_point = copy._energy_point;
    this->_attack_damage = copy._attack_damage;
    std::cout << "ScavTrap " << this->_name << " Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    this->_hit_point = 100;
    this->_energy_point = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap " << this->_name << " Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " Deconstructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hit_point = other._hit_point;
        this->_energy_point = other._energy_point;
        this->_attack_damage = other._attack_damage;
    }
    std::cout << "ScavTrap " << this->_name << " Assignation operator called" << std::endl;   
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hit_point == 0 || this->_energy_point == 0)
    {
        std::cout << "ScavTrap " << this->_name << " can't attack!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
    this->_energy_point--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}