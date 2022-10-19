/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:04:18 by recarlie          #+#    #+#             */
/*   Updated: 2022/10/17 21:32:12 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iostream>

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