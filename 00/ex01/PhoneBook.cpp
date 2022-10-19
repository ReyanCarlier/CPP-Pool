#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->contacts = new Contact[8];
    this->nbContacts = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook destructor called" << std::endl;
    return ;
}

bool isNumber(std::string string)
{
    for (size_t i = 0; i < string.length() - 1; i++)
        if (!std::isdigit(string[i]))
            return false;
    return true;
}

void PhoneBook::addContact()
{
    std::string tmp;
    int index = 0;

    if (this->nbContacts == 8)
        deleteContact(0);
    index = this->nbContacts;
        
    std::cout << "ADD CONTACT FORM" << std::endl;

    std::cout << "Enter first name:" << std::endl;
    std::getline(std::cin >> std::ws, tmp);
    if (tmp.length() == 0)
    {
        std::cout << "Field cannot be empty." << std::endl;
        return deleteContact(index);
    }
    this->contacts[index].setFirstName(tmp);

    std::cout << "Enter last name:" << std::endl;
    std::getline(std::cin >> std::ws, tmp);
    if (tmp.length() == 0)
    {
        std::cout << "Field cannot be empty." << std::endl;
        return deleteContact(index);
    }
    this->contacts[index].setLastName(tmp);

    std::cout << "Enter nickname:" << std::endl;
    std::getline(std::cin >> std::ws, tmp);
    if (tmp.length() == 0)
    {
        std::cout << "Field cannot be empty." << std::endl;
        return deleteContact(index);
    }
    this->contacts[index].setNickname(tmp);

    std::cout << "Enter phone number:" << std::endl;
    std::getline(std::cin >> std::ws, tmp);
    if (tmp.length() == 0)
    {
        std::cout << "Field cannot be empty." << std::endl;
        return deleteContact(index);
    }
    if (!isNumber(tmp))
    {
        std::cout << "Phone number can only be made of digits." << std::endl;
        return deleteContact(index);
    }
    this->contacts[index].setPhoneNumber(tmp);
    std::cout << "Enter darkest secret:" << std::endl;
    
    std::getline(std::cin >> std::ws, tmp);
    if (tmp.length() == 0)
    {
        std::cout << "Everyone has a secret, please, share next time." << std::endl;
        return deleteContact(index);
    }
    this->contacts[index].setDarkestSecret(tmp);

    this->nbContacts++;
    return ;
}

void PhoneBook::searchContact(void)
{
    int     index;
    std::string tmp;

    if (this->nbContacts == 0)
    {
        std::cout << "No contacts." << std::endl;
        return ;
    }
    displayContacts();
    std::cout << "Enter choosen index:" << std::endl;
    std::cin >> tmp;
    if (!isNumber(tmp))
        return;
    index = atoi(tmp.c_str());
    if (index < 0 || index > this->nbContacts - 1)
        return ;
    this->contacts[index].display();
    return ;
}

void PhoneBook::displayContacts(void)
{
    std::string element = "";
    size_t      elementLength = 0;

    for (int i = 0; i < this->nbContacts; i++)
    {
        std::cout << i << " | ";
        element = this->contacts[i].getFirstName();
        elementLength = element.length();
        if (elementLength < 10)
            for (size_t j = 0; j < 10 - elementLength; j++)
                std::cout << ' ';
        else if (elementLength > 10)
        {
            element.resize(10);
            element.at(9) = '.';
        }
        std::cout << element << " | ";

        element = this->contacts[i].getLastName();
        elementLength = element.length();
        if (elementLength < 10)
            for (size_t j = 0; j < 10 - elementLength; j++)
                std::cout << ' ';
        else if (elementLength > 10)
        {
            element.resize(10);
            element.at(9) = '.';
        }
        std::cout << element << " | ";

        element = this->contacts[i].getNickname();
        elementLength = element.length();
        if (elementLength < 10)
            for (size_t j = 0; j < 10 - elementLength; j++)
                std::cout << ' ';
        else if (elementLength > 10)
        {
            element.resize(10);
            element.at(9) = '.';
        }
        std::cout << element << std::endl;
    }
}

void PhoneBook::deleteContact(int index)
{
    if (this->nbContacts > 0)
    {
        for (int i = index; i < this->nbContacts - 1; i++)
            this->contacts[i] = this->contacts[i + 1];
        this->nbContacts--;
    }
    return ;
}
