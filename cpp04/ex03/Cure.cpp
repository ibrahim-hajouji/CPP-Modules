/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:00:12 by ihajouji          #+#    #+#             */
/*   Updated: 2024/12/05 23:26:04 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure has been constructed" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
    std::cout << "Cure has been copied" << std::endl;
}

Cure const &Cure::operator=(Cure const &src)
{
    if (this != &src)
        AMateria::operator=(src);
    std::cout << "Cure has been assigned" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure has been destructed" << std::endl;
}

AMateria    *Cure::clone() const
{
    AMateria *copy = new Cure(*this);
    return (copy);
}

void    Cure::use(ICharacter &target)
{
    std::cout << "\033[31m" << "* heals " << target.getName() << "'s wounds *" << "\033[0m" << std::endl;
}

