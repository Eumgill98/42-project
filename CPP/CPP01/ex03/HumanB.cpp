#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon &weapon)
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
    if (this->_weapon) 
        std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon! " << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}