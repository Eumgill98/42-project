#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

void Contact::_print_value(std::string &value)
{
    std::cout << "|";
    if (value.length() > 10)
        std::cout << value.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << value;
}

void Contact::set_contact(
    std::string first_name, \
    std::string last_name, \
    std::string nickname, \
    std::string phone_number, \
    std::string darkest_secret \
)
{
    this->_first_name = first_name;
    this->_last_name = last_name;
    this->_nickname = nickname;
    this->_phone_number = phone_number;
    this->_darkest_secret = darkest_secret;
}

void Contact::get_contact(int idx)
{
    std::cout << "|" << std::setw(10) << idx;
    _print_value(this->_first_name);
    _print_value(this->_last_name);
    _print_value(this->_nickname);
    std::cout << "|" << std::endl;
}