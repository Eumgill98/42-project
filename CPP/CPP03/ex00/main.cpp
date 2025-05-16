#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap A = ClapTrap("A");
    ClapTrap B = ClapTrap("B");

    std::cout << std::endl;
    A.attack("C");
    std::cout << std::endl;
    A.attack("D");
    std::cout << std::endl;

    B.takeDamage(9);
    std::cout << std::endl;
    B.beRepaired(9);
    std::cout << std::endl;
    B.takeDamage(10);
    std::cout << std::endl;
    B.attack("A");
    std::cout << std::endl;
}