/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:24:10 by snegi             #+#    #+#             */
/*   Updated: 2024/06/26 12:24:26 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() 
{
    PhoneBook phoneBook;
    std::string command;
    while (true) 
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (command == "ADD")
         {
            Contact newContact;
            std::string input;
            do {
                std::cout << "Enter first name: ";
                std::getline(std::cin, input);
                if (input.empty())
                    std::cout << "First name cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setFirstName(input);
           do {
                std::cout << "Enter last name: ";
                std::getline(std::cin, input);
                if (input.empty())
                    std::cout << "Last name cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setLastName(input);
           do {
                std::cout << "Enter nickname: ";
                std::getline(std::cin, input);
                if (input.empty())
                    std::cout << "Nickname cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setNickname(input);
            do {
                std::cout << "Enter phone number: ";
                std::getline(std::cin, input);
                if (input.empty())
                    std::cout << "Phone number cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setPhoneNumber(input);
           do {
                std::cout << "Enter darkest secret: ";
                std::getline(std::cin, input);
                if (input.empty())
                    std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setDarkestSecret(input);
            phoneBook.addContact(newContact);
        } 
         else if (command == "SEARCH") 
        {
            if (phoneBook.isEmpty()) {
                std::cout << "No contacts available." << std::endl;
            } else {
                phoneBook.displayContacts();
                std::cout << "Enter the index of the contact to display: ";
                std::getline(std::cin, command);
                std::stringstream ss(command);
                int index;
                ss >> index;
                if (ss.fail())
                    std::cout << "Invalid index" << std::endl;
                else 
                    phoneBook.displayContactDetails(index);
            }
        } 
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command. Please try again." << std::endl;
    }
    return 0;
}

