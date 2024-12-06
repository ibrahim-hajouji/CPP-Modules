/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:53:52 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/07 21:49:54 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string formatted_str(std::string   str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void    PhoneBook::add_contact()
{
    std::string fname;
    std::string lname;
    std::string nname;
    std::string pnumber;
    std::string dsecret;

    std::cout << "Enter the First Name: " << std::endl;
    std::getline(std::cin, fname);
    if (fname.empty())
    {
        std::cout << "Error: First Name is required" << std::endl;
        return;
    }

    std::cout << "Enter the Last Name: " << std::endl;
    std::getline(std::cin, lname);
    if (lname.empty())
    {
        std::cout << "Error: Last Name is required" << std::endl;
        return;
    }

    std::cout << "Enter the Nickname: " << std::endl;
    std::getline(std::cin, nname);
    if (nname.empty())
    {
        std::cout << "Error: Nickname is required" << std::endl;
        return;
    }
    
    std::cout << "Enter the Phone Number: " << std::endl;
    std::getline(std::cin, pnumber);
    if (pnumber.empty())
    {
        std::cout << "Error: Phone Number is required" << std::endl;
        return;
    }
    if (pnumber.length() != 10 || !std::all_of(pnumber.begin(), pnumber.end(), ::isdigit))
    {
        std::cout << "Error: Phone number must be 10 digits" << std::endl;
        return;
    }
    
    std::cout << "Enter the Dark Secret: " << std::endl;
    std::getline(std::cin, dsecret);
    if (dsecret.empty())
    {
        std::cout << "Error: Dark Secret is required" << std::endl;
        return;
    }
    if (total_contacts == 8)
    {
        std::cout << "Your PhoneBook is full, so i replaced \"" << contacts[index].get_fname() << "\" with the new contact \"" << fname << "\", [\"" << contacts[index].get_fname() <<"\" was useless anyways]"<< std::endl;
        contacts[index].set_contact_infos(fname, lname, nname, pnumber, dsecret);
    }
    else
    {
        contacts[total_contacts].set_contact_infos(fname, lname, nname, pnumber, dsecret);
        total_contacts++;
    }
    index = (index + 1) % 8;
}


void    PhoneBook::search_contact()
{
    if (!total_contacts)
    {
        std::cout << "No contacts to display" << std::endl;
        return ;
    }
    std::cout << "  index   |first name| last name| nickname " << std::endl;
    
    for(int i = 0; i < total_contacts; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << formatted_str(contacts[i].get_fname()) << "|";
        std::cout << std::setw(10) << formatted_str(contacts[i].get_lname()) << "|";
        std::cout << std::setw(10) << formatted_str(contacts[i].get_nname()) << std::endl;
    }
    
    unsigned long long id = 0;
    std::string str_index;
    std::cout << "Enter the index of the contact you want to display" << std::endl;
    std ::getline(std::cin, str_index);
    if (!str_index.length() || !std::all_of((str_index).begin(), (str_index).end(), ::isdigit))
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    try
    {
        id = std::stoull(str_index);
        if (id > 2147483647)
        {
            std::cout << "Invalid index" << std::endl;
            return ;
        }
        
        // Check if the index is within a valid range
        if ((int)id >= 0 && (int)id < total_contacts)
            contacts[(int)id].display_contact_infos();
        else
            std::cout << "Invalid index" << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Index is out of range" << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid index" << std::endl;
    }
}