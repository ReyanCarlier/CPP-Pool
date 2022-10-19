#include "Contact.hpp"
#include "PhoneBook.hpp"

# ifndef IOSTREAM_HPP
#  include <iostream>
# endif

int main(void)
{
    PhoneBook phoneBook;

    while (1)
    {
        std::string command;
        std::cout << "You can either ADD or SEARCH a contact or EXIT: ";
        std::cin >> command;

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
    }
    delete[] phoneBook.contacts;
    return (0);
}