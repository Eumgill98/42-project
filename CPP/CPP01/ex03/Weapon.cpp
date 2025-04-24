#include "Weapon.hpp"

Weapon::Weapon(void)
{
    return ;
}

Weapon::Weapon(std::string type)
{
    this->setType(type);
}

Weapon::~Weapon(void)
{
    return ;
}

const std::string &Weapon::getType() const
{
	return (this->_type);
}

void    Weapon::setType(std::string new_type)
{
    this->_type = new_type;
}