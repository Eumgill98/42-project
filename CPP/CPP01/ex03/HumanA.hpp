#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        Weapon& _weapon;
        std::string _name;

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);

        void  attack(void);
} ;

#endif /* __HUMANA_HPP__ */