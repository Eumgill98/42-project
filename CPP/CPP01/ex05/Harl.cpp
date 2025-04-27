#include "Harl.hpp"

Harl::Harl(void)
{
    funcArr[0] = &Harl::_debug;
    funcArr[1] = &Harl::_info;
    funcArr[2] = &Harl::_warning;
    funcArr[3] = &Harl::_error;
}

Harl::~Harl(void)
{
    return ;
}

void Harl::_debug(void)
{
    std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
    std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int idx = 0;
    while (idx < 4)
    {
        if (level == levels[idx])
        {
            (this->*funcArr[idx])();
            return ;
        }
        idx++;
    }
}