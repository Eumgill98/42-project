#include "DiamondTrap.hpp"

int main() {
    std::cout << "===== DiamondTrap 생성자 테스트 =====" << std::endl;
    DiamondTrap diamond1("DI4M");
    std::cout << std::endl;

    std::cout << "===== DiamondTrap 멤버 함수 테스트 =====" << std::endl;
    diamond1.attack("target1");         // ScavTrap::attack()
    diamond1.takeDamage(30);            // ClapTrap::takeDamage()
    diamond1.beRepaired(20);            // ClapTrap::beRepaired()
    diamond1.whoAmI();                  // DiamondTrap::whoAmI()
    std::cout << std::endl;

    std::cout << "===== DiamondTrap 복사 생성자 테스트 =====" << std::endl;
    DiamondTrap diamond2(diamond1);
    diamond2.whoAmI();
    std::cout << std::endl;

    std::cout << "===== DiamondTrap 대입 연산자 테스트 =====" << std::endl;
    DiamondTrap diamond3;
    diamond3 = diamond1;
    diamond3.whoAmI();
    std::cout << std::endl;

    std::cout << "===== 소멸자 체인 확인 =====" << std::endl;
    return 0;
}