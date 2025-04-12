#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string _name;
    
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);    

        void announce(void) const;
} ;

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif /* __ZOMBIE_HPP__ */
