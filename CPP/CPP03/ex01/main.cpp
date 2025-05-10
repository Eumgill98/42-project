#include "ScavTrap.hpp"

int main() {
    std::cout << "===== ScavTrap 생성자 테스트 =====" << std::endl;
    ScavTrap scav1("SC4V");
    std::cout << std::endl;

    std::cout << "===== ScavTrap 멤버 함수 테스트 =====" << std::endl;
    scav1.attack("target1");         
    scav1.takeDamage(42);            
    scav1.beRepaired(21);            
    scav1.guardGate();               
    std::cout << std::endl;

    std::cout << "===== ScavTrap 복사 생성자 테스트 =====" << std::endl;
    ScavTrap scav2(scav1);
    scav2.guardGate();
    std::cout << std::endl;

    std::cout << "===== ScavTrap 대입 연산자 테스트 =====" << std::endl;
    ScavTrap scav3;
    scav3 = scav1;
    scav3.guardGate();
    std::cout << std::endl;

    std::cout << "===== 소멸자 체인 확인 =====" << std::endl;

    return 0;
}