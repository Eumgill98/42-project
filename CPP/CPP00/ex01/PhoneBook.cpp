#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    _full = false;
    _now_idx = 0;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

PhoneBook::_is_valid_value(std::string value, ValueType type)
{
    if (type == FirstName || type == LastName || type == Nickname)
    {
        for (char c : value)
        {
            if (!std::isalpha(c) && !(c >= 0xAC00 && c <= 0xD7A3))
            {
                std::cout << c << " is not valid value. Try Again !" << std::endl;
                return false ;
            }
        }
    }
    else if (type == PhoneNumber)
    {
        for (char c : value)
        {
            if (!isdigit(c))
            {
                std::cout << c << " is not digit. Try Again !" << std::endl;
                return false ;
            }
        }
    }
    return true;
}

PhoneBook::_read_contact(std::string &value, ValueType type, char *instruct)
{
    while (true)
    {
        std::cout << instruct << std::endl;
        std::getline(std::cin, value);

        if (vale.empty())
        {
            std::cout << "Input can't be empty. Try Again !!" << std::endl;
            continue ;
        }

        if (!_is_valid_value(value, type))
            continue ;
        break ;
    }
}

PhoneBook::add_contact(void)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    _read_contact(first_name, FirstName, "1. First Name:");
    _read_contact(last_name, LastName, "2. Last Name:");
    _read_contact(nickname, Nickname, "3. Nickname:");
    _read_contact(phone_number, PhoneNumber, "4. PhoneNumber:");
    _read_contact(darkest_secret, DarkestSecret, "5. DarkestSecret:");

    if (this->_full)
    {
        for (int i = 1; i < 8; i++) {
            this->_contact[i - 1] = this->_contact[i]
            
        }
        this->_contact[7].set_contact(first_name, last_name, nickname, phone_number, darkest_secret) 
    }
    else
    {
        this->_contact[this->_now_idx].set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
        this->_now_idx++;
        if (this->_now_idx == 8)
            this->_full = true ;
    }
}

PhoneBook::search_contact(void)
{

}