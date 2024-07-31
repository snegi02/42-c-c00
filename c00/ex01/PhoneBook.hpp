/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:26:24 by snegi             #+#    #+#             */
/*   Updated: 2024/06/26 12:26:26 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> 

class PhoneBook 
{
private:
    Contact contacts[8];
    int currentIndex;
    int contactCount;

    std::string formatField(const std::string& str) const;

public:
    PhoneBook();

    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContactDetails(int index) const;
    bool isEmpty() const; 
};

#endif