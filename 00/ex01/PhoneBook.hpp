#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# ifndef IOSTREAM_HPP
#  include <iostream>
# endif

# ifndef STRING_HPP
#  include <string>
# endif

# ifndef STDLIB_H
#  include <stdlib.h>
# endif

class PhoneBook {
    public:

        PhoneBook(void);
        ~PhoneBook(void);

        void    addContact(void);
        void    searchContact(void);
        void    displayContacts(void);
        void    displayContact(int);
        void    deleteContact(int);

        Contact *contacts;
        int     nbContacts;      
};

#endif