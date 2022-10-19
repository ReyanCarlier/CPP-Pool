/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:21:03 by recarlie          #+#    #+#             */
/*   Updated: 2022/10/17 19:39:36 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
    
    return ;
}

Contact::~Contact(void)
{
    std::cout << "Contact destructor called" << std::endl;
    return ;
}

void    Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
    return ;
}

void    Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
    return ;
}

void    Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
    return ;
}   

void    Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
    return ;
}

void    Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
    return ;
}

std::string Contact::getFirstName(void) const
{
    return this->firstName;
}

std::string Contact::getLastName(void) const
{
    return this->lastName;
}

std::string Contact::getNickname(void) const
{
    return this->nickname;
}

std::string Contact::getPhoneNumber(void) const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
    return this->darkestSecret;
}

void    Contact::display(void) const
{
    std::cout << "First Name: " << this->firstName << std::endl;
    std::cout << "Last Name: " << this->lastName << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone Number: " << this->phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
    return ;
}
