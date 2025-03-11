#include "Contact.hpp"

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
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