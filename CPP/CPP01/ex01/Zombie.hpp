#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string _name;
    
    public:
        Zombie(void);
        ~Zombie(void);    

        void set_name(std::string name);
        void announce(void) const;
} ;

Zombie *zombieHorde(int N, std::string name);

#endif /* __ZOMBIE_HPP__ */
