#ifndef __WEAPON_HPP_
#define __WEAPON_HPP_

#include <string>

class Weapon {
    private:
        std::string _type;

    public:
        Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);

        const std::string &getType() const;
        void setType(std::string new_type);
} ;

#endif /* __WEAPON_HPP_ */

