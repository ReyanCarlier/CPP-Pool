#include "Contact.hpp"
#include "PhoneBook.hpp"

# ifndef IOSTREAM_HPP
#  include <iostream>
# endif

int main(void)
{
    PhoneBook phoneBook;

	std::cout << "               _.===========================._\n\
            .'`  .-  - __- - - -- --__--- -.  `'.\n\
        __ / ,'`     _|--|_________|--|_     `'. \n\
      /'--| ;    _.'\\ |  '         '  | /'._    ; |\n\
     //   | |_.-' .-'.'    -  -- -    '.'-. '-._| |\n\
    (\\)   \\\"` _.-` /                     \\ `-._ `/\"\n\
    (\\)    \\`-\\`    /      .---------.      \\    `-`\n\
    (\\)           |      ||1||2||3||      |\n\
   (\\)            |      ||4||5||6||      |\n\
  (\\)             |      ||7||8||9||      |\n\
 (\\)           ___|      ||*||0||#||      |\n\
 (\\)          /.--|      '---------'      |\n\
  (\\)        (\\)  |\\_  _  __   _   __  __/|\n\
 (\\)        (\\)   |                       |\n\
(\\)_._._.__(\\)    |                       |\n\
 (\\\\jgs\\\\)      '.___________________.'\n\
  '-'-'-'--'" << std::endl;
    while (1)
    {
        std::string command;
        std::cout << "You can either ADD or SEARCH a contact or EXIT: ";
        std::getline(std::cin >> std::ws, command);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
		else if (command == "")
			break;
		else
			std::cout << "Invalid command." << std::endl;
    }
    return (0);
}