#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   PhoneBook;
    std::string command;

    while (true)
    {
        std::cout << "command [ADD, SEARCH, EXIT] :" << std::endl;
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "PhoneBook Program Exit By ^D." << std::endl;
            return (0);
        }
        else if (command.compare("ADD") == 0)
            PhoneBook.add_contact();
        else if (command.compare("SEARCH") == 0)
            PhoneBook.search_contact();
        else if (command.compare("EXIT") == 0)
        {
            std::cout << "PhoneBook Program Exit By Exit command." << std::endl;
            return (0);
        }
        else
            std::cout << "[ \"" << command << "\" ] is wrong command !!" << std::endl;
    }
    return (0);
}