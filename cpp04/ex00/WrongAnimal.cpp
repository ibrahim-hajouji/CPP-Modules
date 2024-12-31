/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:48:28 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/30 23:48:47 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "Default WrongAnimal";
    std::cout << "\033[31m" << "WrongAnimal: " << "\033[0m" << type << " has been constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type)
{
    this->type = type;
    std::cout << "\033[31m" << "WrongAnimal: " << "\033[0m" << type << " has been constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    *this = src;
    std::cout << "\033[31m" << "WrongAnimal: " << "\033[0m" << type << " has been copied" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &src)
{
    if (this != &src)
    {
        this->type = src.type;
    }
    std::cout << "\033[31m" << "WrongAnimal: " << "\033[0m" << type << " has been assigned" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[31m" << "WrongAnimal: " << "\033[0m" << type << " has been destructed" << std::endl;
}

void    WrongAnimal::makeSound()
{
    std::cout << "\033[31m" << "WrongAnimal: " << "\033[0m" << type << " is yapping" <<std::endl;
}
