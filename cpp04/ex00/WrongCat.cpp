/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:49:01 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/30 23:49:04 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()  : WrongAnimal("WrongCat")
{
    this->name = "Snow";
    std::cout << "\033[33m" << "WrongCat: " << "\033[0m" << name << " has been constructed" << std::endl;
}

WrongCat::WrongCat(const std::string &name) : WrongAnimal("WrongCat")
{
    this->name = name;
    std::cout << "\033[33m" << "WrongCat: " << "\033[0m" << name << " has been constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
    *this = src;
     std::cout << "\033[33m" << "WrongCat: " << "\033[0m" << name << " has been copied" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat   &src)
{
    if (this != &src)
    {
        this->name = src.name;
        WrongAnimal::operator=(src);
    }
    std::cout << "\033[33m" << "WrongCat: " << "\033[0m" << name << " has been assigned" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "\033[33m" << "WrongCat: " << "\033[0m" << name << " has been destructed" << std::endl;
}

void    WrongCat::makeSound()
{
    std::cout << "\033[33m" << "WrongCat: " << "\033[0m" << name << " is meowing" << std::endl;   
}