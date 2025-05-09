#include "ScavTrap.hpp"

int main() {
    ScavTrap st("Serena");
    st.attack("target1");
    st.takeDamage(30);
    st.beRepaired(20);
    st.guardGate();

    std::cout << "----- Copy/Assignment/Destruction Test -----" << std::endl;
    ScavTrap st2(st);
    ScavTrap st3;
    st3 = st2;
    return 0;
}
