/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 05:06:56 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/05 23:26:35 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice has been constructed" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
    std::cout << "Ice has been copied" << std::endl;
}

Ice const &Ice::operator=(Ice const &src)
{
    if (this != &src)
        AMateria::operator=(src);
    std::cout << "Ice has been assigned" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice has been destructed" << std::endl;
}

AMateria    *Ice::clone() const
{
    AMateria *copy = new Ice(*this);
    return (copy);
}

void    Ice::use(ICharacter &target)
{
    std::cout << "\033[33m" << "* shoots an ice bolt at " << target.getName() << " *" << "\033[0m" << std::endl;
}