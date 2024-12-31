/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:02:25 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/12 01:36:56 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()  : Animal("Dog")
{
    this->name = "Arya";
    this->brain = new Brain();
    if (!this->brain)
    {
        std::cout << "Dog brain alloDogion have been failed" << std::endl;
        exit(1);
    }
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " has been constructed" << std::endl;
}

Dog::Dog(const std::string &name) : Animal("Dog")
{
    this->name = name;
    this->brain = new Brain();
    if (!this->brain)
    {
        std::cout << "Dog brain alloDogion have been failed" << std::endl;
        exit(1);
    }
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
        this->brain = new Brain();
        if (!this->brain)
        {
            std::cout << "Dog brain allocation have been failed" << std::endl;
            exit(1);
        }
        *this->brain = *src.brain;
    }
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " has been assigned" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete (this->brain);
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " has been destructed" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "\033[34m" << "Dog: " << "\033[0m" << name << " is barking" << std::endl;   
}

const std::string &Dog::_getIdea(int index) const
{
    return (brain->getIdea(index));
}

void    Dog::_setIdea(const std::string &idea, int index)
{
    brain->setIdea(idea, index);
}