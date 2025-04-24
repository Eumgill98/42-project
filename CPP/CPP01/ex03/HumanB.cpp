#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon weapon)
{
    this->_name = name;
    this->_weapon = &weapon;
}

HumanB::~HumanB(void)
{
    return ;
}

void HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->(*_weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}