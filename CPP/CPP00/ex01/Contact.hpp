#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
        int         _idx;

    public:
        void    set_contact(std::string first_name \
                            std::string last_name \
                            std::string nickname \
                            std::string phone_number \
                            std::string darkest_secret \
                            int idx
                        );
}

#endif