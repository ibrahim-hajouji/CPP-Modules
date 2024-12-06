/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:15:58 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/01 14:05:03 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::set_contact_infos(std::string Fname, std::string Lname, std::string Nname, std::string Pnumber, std::string Dsecret)
{
    first_name = Fname;
    last_name = Lname;
    nickname = Nname;
    phone_number = Pnumber;
    dark_secret = Dsecret;
}

void    Contact::display_contact_infos()
{
    std::cout << "first Name : " << first_name << std::endl;
    std::cout << "Last Name : " << last_name << std::endl;
    std::cout << "Nick Name : " << nickname << std::endl;
    std::cout << "Phone number : " << phone_number << std::endl;
    std::cout << "Darkest Secret : " << dark_secret << std::endl;
}

std::string Contact::get_fname() const
{
    return (first_name);
}
std::string Contact::get_lname() const
{
    return (last_name);
}
std::string Contact::get_nname() const
{
    return (nickname);
}
std::string Contact::get_pnumber() const
{
    return (phone_number);
}
std::string Contact::get_dsecret() const
{
    return (dark_secret);
}
