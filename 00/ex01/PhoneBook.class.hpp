/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:05:13 by recarlie          #+#    #+#             */
/*   Updated: 2022/10/17 19:20:26 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.class.hpp"
# include <string.h>
# include <stdlib.h>

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