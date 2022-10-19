#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# ifndef IOSTREAM_HPP
#  include <iostream>
# endif

# ifndef STRING_HPP
#  include <string>
# endif

class Contact {
    public:

        Contact(void);
        ~Contact(void);

        void    setFirstName(std::string);
        void    setLastName(std::string);
        void    setNickname(std::string);
        void    setPhoneNumber(std::string);
        void    setDarkestSecret(std::string);

        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;
        
        void    display(void) const;

    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif