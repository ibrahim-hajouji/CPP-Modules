/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:02:25 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/12 01:12:01 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()  : Animal("Dog")
{
    this->name = "Arya";
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " has been constructed" << std::endl;
}

Dog::Dog(const std::string &name) : Animal("Dog")
{
    this->name = name;
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " has been constructed" << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
    *this = src;
     std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " has been copied" << std::endl;
}

Dog &Dog::operator=(const Dog   &src)
{
    if (this != &src)
    {
        this->name = src.name;
        Animal::operator=(src);
    }
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " has been assigned" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " has been destructed" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " is barking" << std::endl;   
}