#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype>

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

        bool    _is_valid_value(string::string value, ValueType type);
        void    _read_contact(std::string &value, ValueType type, char *instruct);

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void    add_contact(void);
        void    search_contact(void);       
}
#endif