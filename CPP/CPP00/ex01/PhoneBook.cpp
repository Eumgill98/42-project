#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    _full = false;
    _now_idx = 0;
}

PhoneBook::add_contact(void)
{
    // 전화 번호 추가
    // 1. 값 입력 받기
    // 2. 타입 체크
    // 3. 올바르지 않은 값이라면 다시 입력 받게
    // 4. 추가 
    // 4.1 전화번호 부의 연락처가 꽉 차있다면 가장 오래된거 지우기
    // 4.2 아니라면 추가 및 now_idx ++ 1 && 꽉 찼는지 확인
}

PhoneBook::search_contact(void)
{

}