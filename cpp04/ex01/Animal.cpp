/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:59:18 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/03 03:08:46 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type = "Default Animal";
    std::cout << "\033[31m" << "Animal: " << "\033[0m" << type << " has been constructed" << std::endl;
}

Animal::Animal(const std::string &type)
{
    this->type = type;
    std::cout << "\033[31m" << "Animal: " << "\033[0m" << type << " has been constructed" << std::endl;
}

Animal::Animal(const Animal &src)
{
    *this = src;
    std::cout << "\033[31m" << "Animal: " << "\033[0m" << type << " has been copied" << std::endl;
}

Animal  &Animal::operator=(const Animal &src)
{
    if (this != &src)
    {
        this->type = src.type;
    }
    std::cout << "\033[31m" << "Animal: " << "\033[0m" << type << " has been assigned" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "\033[31m" << "Animal: " << "\033[0m" << type << " has been destructed" << std::endl;
}

void    Animal::makeSound()
{
    std::cout << "\033[31m" << "Animal: " << "\033[0m" << type << " is yapping" <<std::endl;
}
