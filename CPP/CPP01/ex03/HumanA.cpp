#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapone)
{
    this->_name = name;
    this->_weapon = weapone;
}

HumanA::~HumanA(void)
{
    return ;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}