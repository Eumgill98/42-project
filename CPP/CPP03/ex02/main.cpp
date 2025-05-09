#include "FragTrap.hpp"

int main() {
    std::cout << "===== FragTrap 생성자 테스트 =====" << std::endl;
    FragTrap frag1("FR4G");
    std::cout << std::endl;

    std::cout << "===== FragTrap 멤버 함수 테스트 =====" << std::endl;
    frag1.attack("target1");        
    frag1.takeDamage(42);           
    frag1.beRepaired(21);            
    frag1.highFivesGuys();           
    std::cout << std::endl;

    std::cout << "===== FragTrap 복사 생성자 테스트 =====" << std::endl;
    FragTrap frag2(frag1);
    frag2.highFivesGuys();
    std::cout << std::endl;

    std::cout << "===== FragTrap 대입 연산자 테스트 =====" << std::endl;
    FragTrap frag3;
    frag3 = frag1;
    frag3.highFivesGuys();
    std::cout << std::endl;

    std::cout << "===== 소멸자 체인 확인 =====" << std::endl;

    return 0;
}