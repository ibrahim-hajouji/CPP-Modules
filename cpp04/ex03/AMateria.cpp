/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 04:37:45 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/05 04:19:31 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
    this->type = type;
    std::cout << "AMateria " << type << " has been constructed" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
    std::cout << "AMateria has been copied" << std::endl;
    *this = src;
}

AMateria    const &AMateria::operator=(AMateria const &src)
{   
    std::cout << "AMateria has been assigned" << std::endl;
    if (this != &src)
        this->type = src.getType();
    return (*this);    
}

AMateria::~AMateria()
{
    std::cout << "AMateria " << type << " has been deconstructed" << std::endl;
}

std::string const &AMateria::getType() const 
{
    return (this->type);
}

