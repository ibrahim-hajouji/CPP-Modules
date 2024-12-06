/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:17:47 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/06 13:12:08 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class   Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string dark_secret;
    
    public :
        void    set_contact_infos(std::string Fname, std::string Lname, std::string Nname, std::string Pnumber, std::string Dsecret);
        void    display_contact_infos();

        std::string get_fname() const;
        std::string get_lname() const;
        std::string get_nname() const;
        std::string get_pnumber() const;
        std::string get_dsecret() const;
        
};

#endif
