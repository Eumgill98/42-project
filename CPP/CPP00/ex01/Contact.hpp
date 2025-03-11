#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Contact {
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

        void _print_value(std::string &value);

    public:
        Contact(void);
        ~Contact(void);

        void    set_contact(std::string first_name, \
                            std::string last_name, \
                            std::string nickname, \
                            std::string phone_number, \
                            std::string darkest_secret \
                        );
        void    get_contact(int idx);
} ;

#endif