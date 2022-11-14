#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
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
    for (size_t i = 0; i < string.length(); i++)
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

	// FIRST NAME
		std::cout << "Enter first name:" << std::endl;
		std::getline(std::cin >> std::ws, tmp);
		if (tmp.length() == 0)
		{
			std::cout << "Field cannot be empty." << std::endl;
			return deleteContact(index);
		}
		this->contacts[index].setFirstName(tmp);

	// LAST NAME
		std::cout << "Enter last name:" << std::endl;
		std::getline(std::cin >> std::ws, tmp);
		if (tmp.length() == 0)
		{
			std::cout << "Field cannot be empty." << std::endl;
			return deleteContact(index);
		}
		this->contacts[index].setLastName(tmp);

	// NICKNAME
		std::cout << "Enter nickname:" << std::endl;
		std::getline(std::cin >> std::ws, tmp);
		if (tmp.length() == 0)
		{
			std::cout << "Field cannot be empty." << std::endl;
			return deleteContact(index);
		}
		this->contacts[index].setNickname(tmp);

	// PHONE NUMBER
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

	// DARKEST SECRET
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
    int     	index;
    std::string tmp;

	// CASE NO CONTACTS TO DISPLAY
		if (this->nbContacts == 0)
		{
			std::cout << "You have no friend in your phonebook, sorry." << std::endl;
			return ;
		}

	// SHOW EXISTING CONTACTS
	displayContacts();

	// ASK USER WHICH CONTACT TO DISPLAY
    std::cout << "Enter choosen index:" << std::endl;
    std::cin >> tmp;

	// CHECK INDEX VALIDITY
    if (!isNumber(tmp))
	{
		std::cout << "Choosen index must be a number between 0 and " << this->nbContacts - 1 << "." << std::endl;
        return;
	}
    index = atoi(tmp.c_str());
    if (index < 0 || index > this->nbContacts - 1)
	{
		std::cout << "Choosen index must be a number between 0 and " << this->nbContacts - 1 << "." << std::endl;
        return ;
	}

	// DISPLAY SELECTED CONTACT
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
            std::cout << std::setw(10);
        else if (elementLength > 10)
        {
            element.resize(10);
            element.at(9) = '.';
        }
        std::cout << element << " | ";

        element = this->contacts[i].getLastName();
        elementLength = element.length();
        if (elementLength < 10)
            std::cout << std::setw(10);
        else if (elementLength > 10)
        {
            element.resize(10);
            element.at(9) = '.';
        }
        std::cout << element << " | ";

        element = this->contacts[i].getNickname();
        elementLength = element.length();
        if (elementLength < 10)
            std::cout << std::setw(10);
        else if (elementLength > 10)
        {
            element.resize(10);
            element.at(9) = '.';
        }
        std::cout << element << std::endl;
    }
}

/**
 * @brief 
 * 
 * @param index 
 */
void PhoneBook::deleteContact(int index)
{
    if (this->nbContacts > 0 && index <= this->nbContacts - 1)
    {
		std::cout << "Deleting contact[" << index << "]..." << std::endl;
        for (int i = index; i < this->nbContacts - 1; i++)
            this->contacts[i] = this->contacts[i + 1];
        this->nbContacts--;
    }
    return ;
}