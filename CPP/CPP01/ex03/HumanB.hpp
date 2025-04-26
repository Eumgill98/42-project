#ifndef __HUMANB_HPP_
#define __HUMANB_HPP_

#include <string>
#include <iostream>

#include "Weapon.hpp"

class HumanB {
    private:
        Weapon *_weapon;
        std::string _name;

    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon &weapon);
        ~HumanB(void);

        void attack(void);
        void setWeapon(Weapon &weapon);
} ;

#endif /* __HUMANB_HPP_ */

