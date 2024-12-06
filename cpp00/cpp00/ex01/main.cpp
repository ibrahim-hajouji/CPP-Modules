/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:54:16 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/05 16:35:07 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    PhoneBook phoneBook;
    std::string command;

    (void)av;
    if (ac != 1)
    {
        std::cout << "You must not enter an argument" << std::endl;
        return (1);
    }
    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
        std::getline(std::cin, command);

        if (std::cin.eof())
        {
            std::cout << std::endl;
            return 0;
        }

        if (command == "ADD")
            phoneBook.add_contact();
        else if (command == "SEARCH")
            phoneBook.search_contact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command!" << std::endl;
    }

    return (0);
}