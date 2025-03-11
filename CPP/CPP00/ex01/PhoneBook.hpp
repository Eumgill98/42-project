#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>

class PhoneBook {
    private:
        Contact _contact[8];
        bool    _full;
        int     _now_idx;

        enum ValueType {
            FirstName,
            LastName,
            Nickname,
            PhoneNumber,
            DarkestSecret,
        };

        bool    _is_valid_value(std::string value, ValueType type);
        void    _read_contact(std::string &value, ValueType type, const char *instruct);
        bool    _check_idx_contact(int idx);
        void    _print_idx_contact(int idx);

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void    add_contact(void);
        void    search_contact(void);       
} ;

#endif