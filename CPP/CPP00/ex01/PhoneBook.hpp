#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contact[8];
        bool    _full;
        int     _now_idx;

    public:
        PhoneBook(void);

        void    add_contact(void);
        void    search_contact(void);       
}
#endif