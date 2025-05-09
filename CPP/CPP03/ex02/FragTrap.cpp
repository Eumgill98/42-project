#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("deafault")
{
    this->_hit_point = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
    : ClapTrap(copy._name)
{
    this->_hit_point = copy._hit_point;
    this->_energy_point = copy._energy_point;
    this->_attack_damage = copy._attack_damage;
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    this->_hit_point = 100;
    this->_energy_point = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << " FragTrap Deconstructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    this->_name = other._name;
    this->_hit_point = other._hit_point;
    this->_energy_point = other._energy_point;
    this->_attack_damage = other._attack_damage;
    std::cout << "FragTrap Assignation operator called" << std::endl;
    return *this;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " requests a high five! ✋" << std::endl;
}