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

bool PhoneBook::_is_valid_value(std::string value, ValueType type)
{
    if (type == FirstName || type == LastName)
    {
        for (size_t i = 0; i < value.size(); i++)
        {
            if (!std::isalpha(value[i]))
            {
                std::cout << "\"" << value << "\"" << " is not valid value. Try Again !" << std::endl;
                return false ;
            }
        }
    }
    else if (type == PhoneNumber)
    {
        for (size_t i = 0; i < value.size(); i++)
        {
            if (!isdigit(value[i]))
            {
                std::cout << "\"" << value << "\"" << " is not digit. Try Again !" << std::endl;
                return false ;
            }
        }
    }
    return true;
}

void PhoneBook::_read_contact(std::string &value, ValueType type, const char *instruct)
{
    while (true)
    {
        std::cout << instruct << std::endl;
        std::getline(std::cin, value);

        if (value.empty())
        {
            std::cout << "Input can't be empty. Try Again !!" << std::endl;
            continue ;
        }

        if (!_is_valid_value(value, type))
            continue ;
        break ;
    }
}

bool PhoneBook::_check_idx_contact(int idx)
{
    if (this->_now_idx <= idx)
        return (false);
    return (true);
}

void PhoneBook::_print_idx_contact(int idx)
{
    (void)idx;
    
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    this->_contact[idx].get_contact(idx);
    std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::add_contact(void)
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
            this->_contact[i - 1] = this->_contact[i];
        }
        this->_contact[7].set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
    }
    else
    {
        this->_contact[this->_now_idx].set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
        this->_now_idx++;
        if (this->_now_idx == 8)
            this->_full = true ;
    }
}

void PhoneBook::search_contact(void)
{
    std::string input;
    int         idx;

    while (true)
    {
        std::cout << "Which contact do you want ? Please idx num" << std::endl << "If you want to break [BACK] ( Currently, there are up to " << this->_now_idx << ", start idx is 0 ) :" << std::endl;
        std::getline(std::cin, input);

        if (std::cin.eof())
        {
            std::cout << "PhoneBook Program Exit By Exit input." << std::endl;
            exit(0) ;
        }
        if (input.empty())
        {
            std::cout << "[ \"" << input << "\" ] is wrong idx !!" << std::endl;
            continue ;
        }
        if (input.compare("BACK") == 0)
            break ;
        idx = std::atoi(input.c_str());
        if (_check_idx_contact(idx))
        {
            _print_idx_contact(idx);
            break ;
        }
        else
            std::cout << "[ " << idx << " ] That idx is out of ragne !!! [ Currently, there are up to " << this->_now_idx  << " ]" << std::endl;
    }
}