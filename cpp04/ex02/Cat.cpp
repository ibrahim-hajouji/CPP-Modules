/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:53:18 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/12 01:53:47 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()  : Animal("Cat")
{
    this->name = "Snow";
    this->brain = new Brain();
    if (!this->brain)
    {
        std::cout << "Cat brain allocation have been failed" << std::endl;
        exit(1);
    }
    std::cout << "\033[33m" << "Cat: " << "\033[0m" << name << " has been constructed" << std::endl;
}

Cat::Cat(const std::string &name) : Animal("Cat")
{
    this->name = name;
    this->brain = new Brain();
    if (!this->brain)
    {
        std::cout << "Cat brain allocation have been failed" << std::endl;
        exit(1);
    }
    std::cout << "\033[33m" << "Cat: " << "\033[0m" << name << " has been constructed" << std::endl;
}

Cat::Cat(const Cat &src) : Animal()
{
    *this = src;
     std::cout << "\033[33m" << "Cat: " << "\033[0m" << name << " has been copied" << std::endl;
}

Cat &Cat::operator=(const Cat   &src)
{
    if (this != &src)
    {
        this->name = src.name;
        Animal::operator=(src);
        this->brain = new Brain();
        if (!this->brain)
        {
            std::cout << "Cat brain allocation have been failed" << std::endl;
            exit(1);
        }
        *this->brain = *src.brain;
    }
    std::cout << "\033[33m" << "Cat: " << "\033[0m" << name << " has been assigned" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete (this->brain);
    std::cout << "\033[33m" << "Cat: " << "\033[0m" << name << " has been destructed" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "\033[33m" << "Cat: " << "\033[0m" << name << " is meowing" << std::endl;   
}