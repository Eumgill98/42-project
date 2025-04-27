#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>
#include <iostream>

class Harl {
    private:
        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);
        void (Harl::*funcArr[4])(void);
        
    public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);
    } ;

#endif /* __HARL_HPP__ */