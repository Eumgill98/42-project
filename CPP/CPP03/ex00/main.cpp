#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap A = ClapTrap("A");
    ClapTrap B = ClapTrap("B");

    A.attack("C");
    A.attack("D");

    B.takeDamage(9);
    B.beRepaired(9);
    B.takeDamage(10);
    B.attack("A");
}